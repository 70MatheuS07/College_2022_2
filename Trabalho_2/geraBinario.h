#ifndef GERABINARIO_H
#define GERABINARIO_H

#include <stdlib.h>
#include <stdio.h>
#include "bitmap.h"
#include "Arvore.h"
#include "VetorFreq.h"

#define TAM_LONG_INT 32
#define TAM_INT 16
#define TAM_CHAR 8

void CompactaArvoreTexto(Arv *arvore, char *nomeArquivo, int vet[]);

bitmap *CompactaArvore(Arv *arvore);

bitmap *CompactaTexto(Arv *arvore, char *nomeArquivo);

int RetornaTamanhoTexto(char *nomeArquivo);

bitmap *CorrigiTamanhoTextoBits(char *nomeArquivo, Arv *arvore, bitmap *textoBits);

bitmap *JuntaMapasDeBits(bitmap *arvoreBits, bitmap *textoBits);

bitmap *JuntaTotalBitsComArquivoBits(long long int numTotalBits, bitmap *arvoreTextoBits);

#endif