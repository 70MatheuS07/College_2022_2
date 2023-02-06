CC = gcc
CFLAGS = -g -Wno-everything -pthread -lm

SRCS = $(wildcard *.c)
OBJS = $(SRCS:.c=.o)
HEADERS = $(wildcard *.h)

all: compacta descompacta

compacta: Arvore.o bitmap.o geraBinario.o VetorFreq.o ListaArv.o compacta.o
	$(CC) $(CFLAGS) $^ -o $@

descompacta: Arvore.o bitmap.o geraBinario.o VetorFreq.o ListaArv.o descompacta.o
	$(CC) $(CFLAGS) $^ -o $@

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f *.o compacta descompacta