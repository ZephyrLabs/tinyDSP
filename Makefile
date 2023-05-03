CC=gcc
CFLAGS=-lm

default:
	mkdir build
	cp src -r build/
	cd build

# build libconv
	$(CC) $(CFLAGS) -c -o build/src/libconv.o build/src/libconv/convolution.c

# build libfft
	$(CC) $(CFLAGS) -c -o build/src/libfft.o build/src/libfft/fft.c

# build libfilter
	$(CC) $(CFLAGS) -c -o build/src/libfilter.o build/src/libfilter/filter.c

# build libmem
#(this might need fixing)
	$(CC) $(CFLAGS) -c -o build/src/libmem/fifo/fifo.o build/src/libmem/fifo/fifo.c
	$(CC) $(CFLAGS) -c -c -o build/src/libmem.o build/src/libmem/mem.c

clean:
	rm -rf build