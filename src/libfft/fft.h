/**
 * @file fft.h
 * @author Sravan Senthilnathan
 * @brief Include header for FFT kernel
 * @date 2023-05-03
 * 
 * @copyright Copyright (c) 2023
 * 
 */


#ifndef __FFT_H__
#define __FFT_H__

typedef struct{
    float re;
    float im;
}complex;

/* supplementary functions */

complex complex_sum(complex a, complex b);
complex complex_sub(complex a, complex b);
complex complex_mul(complex a, complex b);
complex complex_scale_by_const(complex a, float y);
float complex_abs(complex a);

complex* fft(float* sequence);

#endif