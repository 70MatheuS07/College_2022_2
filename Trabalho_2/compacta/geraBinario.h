#ifndef GERABINARIO_H
#define GERABINARIO_H

#include <stdlib.h>
#include <stdio.h>
#include "bitmap.h"
#include "Arvore.h"

#define TAM_LONG_LONG_INT 64

#define TAM_INT 16
#define TAM_CHAR 8

void CompactaArvoreTexto(Arv *arvore, char *nomeArquivo);

bitmap *CompactaArvore(Arv *arvore);

bitmap *CompactaTexto(Arv *arvore, char *nomeArquivo);

int RetornaTamanhoTexto(char *nomeArquivo);

bitmap *CorrigiTamanhoTextoBits(char *nomeArquivo, Arv *arvore, bitmap *textoBits);

bitmap *JuntaMapasDeBits(bitmap *arvoreBits, bitmap *textoBits);

bitmap *JuntaTotalBitsComArquivoBits(long long int numTotalBits, bitmap *arvoreTextoBits);

#endif