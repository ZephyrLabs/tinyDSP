/**
 * @file filter.h
 * @author Sravan Senthilnathan
 * @brief include header for filter kernel
 * @date 2023-05-03
 * 
 * @copyright Copyright (c) 2023
 * 
 */


#ifndef __FILTER_H__
#define __FILTER_H__

/* impulse response generating windows */
float* windowLowPass(int order, float fNyquist, float fCutoff);
float* windowHighPass(int order, float fNyquist, float fCutoff);
float* windowBandPass(int order, float fNyquist, float fCutLower, float fCutUpper);
float* windowBandStop(int order, float fNyquist, float fCutLower, float fCutUpper);

/* filter implementation */
void filter(float* inputSignal, float* filterCoefficient);

#endif
