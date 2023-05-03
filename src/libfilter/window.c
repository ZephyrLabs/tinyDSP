/**
 * @file window.c
 * @author Sravan Senthilnathan
 * @brief FIR filter window generator
 * @date 2023-05-03
 * 
 * @copyright Copyright (c) 2023
 * 
 */


#include "filter.h"
#include "../../tinydsp_config.h"

#include <stdlib.h>
#include <math.h>

#define PI 3.141592653

/**
 * @brief Low pass FIR filter coefficent generator
 * 
 * @param order order of the desired filter
 * @param fNyquist frequency of sampling 
 * @param fCutoff cutoff filtering frequency
 * @return float* allocated array of filter coefficients
 */
float* windowLowPass(int order, float fNyquist, float fCutoff){

    int t = (order%2 == 0)?order/2:(order-1)/2; 
    float fNormalized = 2 * PI * fCutoff / fNyquist;

    float* coeff = (float*)malloc(order * sizeof(float));

    for(int n = 0; n < order; n++){

        if(n == t) coeff[n] = fNormalized/PI;
        else coeff[n] = sin(fNormalized * (n - t))/(PI * (n - t));

        #ifdef FILTER_HANNING
            coeff[n] *= 0.5 - 0.5 * cos((2 * PI * n)/(order - 1));
        #endif
        #ifdef FILTER_HAMMING
            coeff[n] *= 0.54 - 0.46 * cos((2 * PI * n)/(order - 1));
        #endif
    }

    return(coeff);
}

/**
 * @brief High pass FIR filter coefficent generator
 * 
 * @param order order of the desired filter
 * @param fNyquist frequency of sampling 
 * @param fCutoff cutoff filtering frequency
 * @return float* allocated array of filter coefficients
 */
float* windowHighPass(int order, float fNyquist, float fCutoff){

    int t = (order%2 == 0)?order/2:(order-1)/2; 
    float fNormalized = 2 * PI * fCutoff / fNyquist;

    float* coeff = (float*)malloc(order * sizeof(float));

    for(int n = 0; n < order; n++){

        if(n == t) coeff[n] = 1 - fNormalized/PI;
        else coeff[n] = - sin(fNormalized * (n - t))/(PI * (n - t));

        #ifdef FILTER_HANNING
            coeff[n] *= 0.5 - 0.5 * cos((2 * PI * n)/(order - 1));
        #endif
        #ifdef FILTER_HAMMING
            coeff[n] *= 0.54 - 0.46 * cos((2 * PI * n)/(order - 1));
        #endif
    }

    return(coeff);
}

/**
 * @brief Band pass FIR filter coefficient generator
 * 
 * @param order order of the desired filter
 * @param fNyquist frequency of sampling
 * @param fCutLower lower cutoff frequency of the pass window
 * @param fCutUpper upper cutoff frequency of the pass window
 * @return float* 
 */
float* windowBandPass(int order, float fNyquist, float fCutLower, float fCutUpper){

    int t = (order%2 == 0)?order/2:(order-1)/2; 
    
    float fNormalLower = 2 * PI * fCutLower / fNyquist;
    float fNormalUpper = 2 * PI * fCutUpper / fNyquist;

    float* coeff = (float*)malloc(order * sizeof(float));

    for(int n = 0; n < order; n++){

        if(n == t) coeff[n] = (fNormalUpper - fNormalLower)/PI;
        else coeff[n] = (sin(fNormalUpper * (n - t)) - sin(fNormalLower * (n - t)))/(PI * (n - t));

        #ifdef FILTER_HANNING
            coeff[n] *= 0.5 - 0.5 * cos((2 * PI * n)/(order - 1));
        #endif
        #ifdef FILTER_HAMMING
            coeff[n] *= 0.54 - 0.46 * cos((2 * PI * n)/(order - 1));
        #endif
    }

    return(coeff);
}

/**
 * @brief Band pass FIR filter coefficient generator
 * 
 * @param order order of the desired filter
 * @param fNyquist frequency of sampling
 * @param fCutLower lower cutoff frequency of the barrier window
 * @param fCutUpper upper cutoff frequency of the barrier window
 * @return float* 
 */
float* windowBandStop(int order, float fNyquist, float fCutLower, float fCutUpper){

    int t = (order%2 == 0)?order/2:(order-1)/2; 
    
    float fNormalLower = 2 * PI * fCutLower / fNyquist;
    float fNormalUpper = 2 * PI * fCutUpper / fNyquist;

    float* coeff = (float*)malloc(order * sizeof(float));

    for(int n = 0; n < order; n++){

        if(n == t) coeff[n] = 1 - (fNormalUpper - fNormalLower)/PI;
        else coeff[n] = - (sin(fNormalUpper * (n - t)) - sin(fNormalLower * (n - t)))/(PI * (n - t));

        #ifdef FILTER_HANNING
            coeff[n] *= 0.5 - 0.5 * cos((2 * PI * n)/(order - 1));
        #endif
        #ifdef FILTER_HAMMING
            coeff[n] *= 0.54 - 0.46 * cos((2 * PI * n)/(order - 1));
        #endif
    }

    return(coeff);
}
