CC=icc
CFLAGS=-Wall -O3 -openmp

for-loop : for-loop.c
	$(CC) -o $@ $< $(CFLAGS)

.PHONY: clean

clean :
	rm -f for-loop