CC=gcc
CFLAGS=-I.

all: printf

DEPS = my_printf.h
OBJ = printf.o my_printf.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

printf: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: clean

clean:
	rm -rf ./*.o