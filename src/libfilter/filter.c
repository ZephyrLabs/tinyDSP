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
#include "../libmem/fifo/fifo.h"

/**
 * @brief inplace filter mapping function 
 * 
 * @param inputSignal input signal sequence
 * @param filterCoefficient designed filter coefficient sequence
 * @param SignalLength input Signal Length
 * @param CoefficientLength filter coefficient length
 */
void filter(float* inputSignal, float* filterCoefficient, int SignalLength, int CoefficientLength){

    int N = CoefficientLength;

    __fifoFloat* x = FifoFloat(N);     // delay buffer
    float y;    // impulse output

    for(int i = 0; i < SignalLength; i++){
        y = 0;

        fifoFloatEnqueue(x, inputSignal[i]);

        for (int j = 0; j < N; j++) y += filterCoefficient[j] * fifoFloatAt(x, j); // filter MAC operation 

        inputSignal[i] = y;
    }
}