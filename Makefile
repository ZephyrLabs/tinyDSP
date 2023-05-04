CC=gcc
CFLAGS=-lm

SRC=src/libconv.o			\
	src/libfft.o			\
	src/filter.o			\
	src/window.o			\
	src/fifo.o

default: $(SRC)
	ar rcs libtinydsp.a $(SRC)
#$(CC) -shared -o $(SRC)

src/libconv.o:
	$(CC) $(CFLAGS) -c -o src/libconv.o src/libconv/convolution.c

src/libfft.o:
	$(CC) $(CFLAGS) -c -o src/libfft.o src/libfft/fft.c

src/filter.o:
	$(CC) $(CFLAGS) -c -o src/filter.o src/libfilter/filter.c

src/window.o:
	$(CC) $(CFLAGS) -c -o src/window.o src/libfilter/window.c

src/fifo.o:
	$(CC) $(CFLAGS) -c -o src/fifo.o src/libmem/fifo/fifo.c

clean:
	rm -rf *.a
	rm -rf src/*.o