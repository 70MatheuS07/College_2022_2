#ifndef LISTA_H
#define LISTA_H

#include "Arvore.h"
#define NUM_ASCII 256
typedef struct listaArv ListaArv;

ListaArv* IniciaListaArv ();

void InsereListaArv (ListaArv* lista, Arv* arv);

void ImprimeListaArv (ListaArv* lista);

//essa função vai servir pra executar o algoritimo de Huffman
Arv* RetiraPrimeiraArvDaLista (ListaArv* lista);

void LiberaListaArv (ListaArv* lista);

//Cria arvores para os caracteres com frequencia diferente de 0 e insere na lista
void PreencheListaArvFrequencia(ListaArv* lista, int V[], int tam);

//Precisa fazer essa função pra pra executar o algoritimo de Huffman
void OrdenaListaArvFrequencia(ListaArv* lista);

int RetornaNumListaArv(ListaArv *lista);

Arv *ExecutaAlgoritimoDeHuffman(ListaArv *lista);

#endif