/**
 * @file filter.c
 * @author Sravan Senthilnathan
 * @brief filter kernel
 * @date 2023-05-03
 * 
 * @copyright Copyright (c) 2023
 * 
 */


#include "filter.h"
#include "../tinydsp_config.h"

/**
 * @brief inplace filter mapping function 
 * 
 * @param inputSignal input signal sequence
 * @param filterCoefficient designed filter coefficient sequence
 */
void filter(float* inputSignal, float* filterCoefficient){

    int N = sizeof(filterCoefficient)/sizeof(float);
    int n = sizeof(inputSignal)/sizeof(float);

    float x[N];     // delay buffer
    float y;    // impulse output

    for(int i = 0; i < n; i++){
        y = 0;

        x[0] = inputSignal[i];

        for (int j = 0; j < N; j++) y += filterCoefficient[j] * x[j]; // filter MAC operation
        for (int j = (N-1); j > 0; j--) x[j] = x[j-1]; // shift delay line 

        inputSignal[i] = y;
    }
}