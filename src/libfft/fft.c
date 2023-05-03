/**
 * @file fft.c
 * @author Sravan Senthilnathan
 * @brief FFT kernel
 * @date 2023-05-03
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "fft.h"
#include "bitLUT.h"

#include <math.h>
#include <stdlib.h>

#define PI 3.141592653

/**
 * @brief produce a bit reversed index for bit reversal permutation
 * 
 * @param n 
 * @return unsigned int 
 */
unsigned int bitrev(int n){
    return (BITLUT[n & 0xff] << 24) | 
           (BITLUT[(n >> 8) & 0xff] << 16) | 
           (BITLUT[(n >> 16) & 0xff] << 8) |
           (BITLUT[(n >> 24) & 0xff]);
}

/**
 * @brief complex data type add
 * 
 * @param a 
 * @param b 
 * @return complex 
 */
complex complex_sum(complex a, complex b){
    complex c;
    c.re = a.re + b.re;
    c.im = a.im + b.im;

    return c;
}

/**
 * @brief complex data type subtract
 * 
 * @param a 
 * @param b 
 * @return complex 
 */
complex complex_sub(complex a, complex b){
    complex c;
    c.re = a.re - b.re;
    c.im = a.im - b.im;

    return c;
}

/**
 * @brief complex data type multiply
 * 
 * @param a 
 * @param b 
 * @return complex 
 */
complex complex_mul(complex a, complex b){
    complex c;
    c.re = (a.re * b.re) - (a.im * b.im);
    c.im = (a.re * b.im) + (a.im * b.re);

    return c;
}

/**
 * @brief complex data type scale
 * 
 * @param a 
 * @param y 
 * @return complex 
 */
complex complex_scale_by_const(complex a, float y){
    a.re *= y;
    a.im *= y;

    return a;
}

/**
 * @brief absolute magnitude of a complex data type
 * 
 * @param a 
 * @return float 
 */
float complex_abs(complex a){
    return sqrt((a.re*a.re) + (a.im*a.im));
}

/**
 * @brief DFT by FFT implementation with cooley-tukey algorithm
 * 
 * @param sequence 
 * @return complex* 
 */
complex* fft(float* sequence){

    int n = sizeof(sequence)/sizeof(float);
    complex* s = (complex*)malloc(n * sizeof(complex));

    for(int i = 0; i < n; i++){
        complex tmp = {sequence[i], 0}; 
        s[i] = tmp;
    }

    // bit reversal permutation
    int bitShift = 0;
    for(int n2 = n; n2 > 1; n2 /= 2) bitShift++;
    bitShift = 32 - bitShift;
    complex t;

    for(unsigned int i = 1; i < n/2; i++){
        unsigned int _i = bitrev(i) >> bitShift;
        t = s[i];
        s[i] = s[_i];
        s[_i] = t; 
    }

    // butterfly computation
    for (int k = 2; k <= n; k *= 2){
        for (int j = 0; j < k / 2; j++){

            //twiddle factor
            complex w = {cos((2 * PI * j) / k), 
                        -sin((2 * PI * j) / k)};

            for (int i = j; i < n; i += k) {
                complex u = s[i];
                complex t = complex_mul(w, s[i + k / 2]);
                s[i] = complex_sum(u, t);
                s[i + k / 2] = complex_sub(u, t);
            }
        }
    }
    
    return s;
}