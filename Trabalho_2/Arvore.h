#ifndef  ARVORE_H
#define  ARVORE_H

typedef struct arv Arv;

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

Arv* CriaArv_Vazia(void);

Arv* CriaArv(int frequencia, char caractere);

void Imprime(Arv* a);
//essa função vai servir pra executar o algoritimo de Huffman
Arv* JuntaArvs(Arv* arv_e, Arv* arv_d);

Arv* Libera(Arv* a);

int RetornaFreqArv(Arv *arvore);

//int ComparaFreqArv(void *arv_1, void *arv_2);

#endif