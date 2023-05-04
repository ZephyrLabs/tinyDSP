# tinyDSP
 A small collection of optimized digital signal processing algorithms.

 Aimed to be both time/processing and space complexity optimized, targetting
 both normal and embedded compute devices, with added support for vector instruction based
 speedups.

Current Implementations:

* [Convolution](src/libconv/)
* [Radix-2 FFT](src/libfft/)
* [FIR filter](src/libfilter/)

Along with custom optimized memory objects
* [FIFO ring buffer](src/libmem/fifo/fifo.h)
