/**
 * @file convolution.c
 * @author Sravan Senthilnathan
 * @brief convolution kernel
 * @date 2023-05-03
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "convolution.h"

/**
 * @brief Fixed point convolution operation
 * 
 * @param y output buffer with fixed point integer
 * @param x input signal
 * @param h impulse response 
 * @param len_x length of the input signal
 * @param len_h length of the impulse response
 */
void convoluteFixed(int* y, int* x, int* h, int len_x, int len_h){
    int len_y = len_x + len_h - 1;
    
    for(int n = 0; n < len_y; n++){
        for(int k = 0; k < len_h; k++){
            if((n - k) >= 0 && (n - k) <= len_h){
                y[n] = y[n] + (x[k] * h[n - k]);
            }
        }
    }
}

/**
 * @brief Floating point convolution operation
 * 
 * @param y output buffer with floating point data
 * @param len_x length of the input signal
 * @param len_h length of the impulse response
 * @param len_x length of the input signal
 * @param len_h length of the impulse response
 */
void convoluteFloat(float* y, float* x, float* h, int len_x, int len_h){
    int len_y = len_x + len_h - 1;

    for(int n = 0; n < len_y; n++){
        for(int k = 0; k < len_h; k++){
            if((n - k) >= 0 && (n - k) <= len_h){
                y[n] = y[n] + (x[k] * h[n - k]);
            }
        }
    }
}