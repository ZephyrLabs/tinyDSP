CC=gcc
CFLAGS=-lm

default: src/libconv.o src/libfft.o src/libfilter.a src/libmem.a
	ar rcs tinydsp.a src/libconv.o src/libfft.o src/libfilter.a src/libmem.a
# $(CC) -shared -o libtinydsp.so src/libconv.o src/libfft.o src/libfilter.o src/libmem.o

src/libconv.o: #src/libconv/convolution.h convolution.c
	$(CC) $(CFLAGS) -fPIC -c -o src/libconv.o src/libconv/convolution.c

src/libfft.o: #src/libfft/fft.h src/libfft/bitLUT.h src/libfft/fft.c
	$(CC) $(CFLAGS) -fPIC -c -o src/libfft.o src/libfft/fft.c

src/libfilter.a: #src/libfilter/filter.h
	$(CC) $(CFLAGS) -fPIC -c -o src/libfilter/window.o src/libfilter/window.c
	$(CC) $(CFLAGS) -fPIC -c -o src/libfilter/filter.o src/libfilter/filter.c
	ar rcs src/libfilter.a src/libfilter/filter.o src/libfilter/window.o

src/libmem.a: src/libmem/fifo/fifo.o
	ar rcs src/libmem.a src/libmem/fifo/fifo.o
	
src/libmem/fifo/fifo.o:
	$(CC) $(CFLAGS) -fPIC -c -o src/libmem/fifo/fifo.o src/libmem/fifo/fifo.c

clean:
	rm -rf build
