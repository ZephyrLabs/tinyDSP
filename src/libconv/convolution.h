/**
 * @file convolution.h
 * @author Sravan Senthilnathan
 * @brief include header for convolution kernel
 * @date 2023-05-03
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef __CONVOLUTION_H__
#define __CONVOLUTION_H__

void convoluteFixed(int* y, int* x, int* h);
void convoluteFloat(float* y, float* x, float* h);

#endif
