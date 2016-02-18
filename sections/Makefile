CC=icc
CFLAGS=-Wall -O3 -openmp

sections : sections.c
	$(CC) -o $@ $< $(CFLAGS)

.PHONY: clean

clean :
	rm -f sections