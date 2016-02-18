CC=icc
CFLAGS=-Wall -O3 -openmp

reduce : reduce.c
	$(CC) -o $@ $< $(CFLAGS)

.PHONY: clean

clean :
	rm -f reduce