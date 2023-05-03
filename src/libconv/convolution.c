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

#if ENABLE_ARM_NEON
    #include "arm_neon.h"
#endif

/**
 * @brief Fixed point convolution operation
 * 
 * @param y output buffer with fixed point integer
 * @param x input signal
 * @param h impulse response
 */
void convoluteFixed(int* y, int* x, int* h){
    int len_x = sizeof(x)/sizeof(int);
    int len_h = sizeof(h)/sizeof(int);

    #ifndef ENABLE_ARM_NEON

    for(int n = 0; n < len_x; n++){
        for(int k = 0; k < len_h; k++){
            if((n - k) >= 0 && (n - k) <= len_h){
                y[n] = y[n] + (x[k] * h[n - k]);
            }
        }
    }

    #endif
    #ifdef ENABLE_ARM_NEON

        int i = 0;
        float32x4_t a, b, c;

        for(int n = 0; n < l; n++){
            i = 0;
            c = vmovq_n_f32(0.0f);
            for(int k = 0 ;k < l1; k++){
                if((n - k) >= 0 && (n - k) <= l2){  
                    a[i] = x[k];
                    b[i] = h[n - k];
                    i++;

                    if(i > 3){
                        c = vmulq_f32(a, b);
                        y[n] = vaddvq_f32(c);

                        c = vmovq_n_f32(0.0f);
                        i = 0;
                    }
                }
            }    
            if (i != 0){ 
                a[i] = 0;

                c = vmulq_f32(a, b);
                y[n] = vaddvq_f32(c);
            }
        }
    #endif
}

/**
 * @brief Floating point convolution operation
 * 
 * @param y output buffer with floating point data
 * @param x input signal
 * @param h impulse response
 */
void convoluteFloat(float* y, float* x, float* h){
    int len_x = sizeof(x)/sizeof(float);
    int len_h = sizeof(h)/sizeof(float);

    #ifndef ENABLE_ARM_NEON

    for(int n = 0; n < len_x; n++){
        for(int k = 0; k < len_h; k++){
            if((n - k) >= 0 && (n - k) <= len_h){
                y[n] = y[n] + (x[k] * h[n - k]);
            }
        }
    }

    #endif
    #ifdef ENABLE_ARM_NEON
    
        int i = 0;
        float32x4_t a, b, c;
    
        for(int n = 0; n < l; n++){
            i = 0;
            c = vmovq_n_f32(0.0f);
            for(int k = 0 ;k < l1; k++){
                if((n - k) >= 0 && (n - k) <= l2){  
                    a[i] = x[k];
                    b[i] = h[n - k];
                    i++;
    
                    if(i > 3){
                        c = vmulq_s32(a, b);
                        y[n] = vaddvq_s32(c);
    
                        c = vmovq_n_s32(0.0f);
                        i = 0;
                    }
                }
            }    
            if (i != 0){ 
                a[i] = 0;
    
                c = vmulq_s32(a, b);
                y[n] = vaddvq_s32(c);
            }
        }
    #endif
}