/**
 * @file tinydsp.h
 * @author Sravan Senthilnathan
 * @brief include header for the library
 * @version 1.0.0
 * @date 2023-05-03
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef __TINYDSP_H__
#define __TINYDSP_H__

#include "src/libconv/convolution.h"
#include "src/libfft/fft.h"
#include "src/libfilter/filter.h"
#include "src/libmem/mem.h"

#define FILTER_HANNING 1
#define FILTER_HAMMING 0

// ARM NEON ISA platform config
#define ENABLE_ARM_NEON 0

#if ENABLE_ARM_NEON
    #define ENABLE_NEON_FP16 0
#endif


#endif