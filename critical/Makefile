CC=icc
CFLAGS=-Wall -O3 -openmp

critical : critical.c
	$(CC) -o $@ $< $(CFLAGS)

.PHONY: clean

clean :
	rm -f critical