#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "ListaArv.h"
#include "VetorFreq.h"
#include "geraBinario.h"

#define ARQUIVO 1

int main(int argc, char *argv[])
{
    int V[NUM_ASCII];

    ZeraVetorFreq(V, NUM_ASCII);
    PreencheVetorFreq(V, NUM_ASCII, argv[ARQUIVO]);

    ListaArv *lista = IniciaListaArv();

    PreencheListaArvFrequencia(lista, V, NUM_ASCII);

    Arv *arvore = CriaArv_Vazia();
    arvore = ExecutaAlgoritimoDeHuffman(lista);

    CompactaArvoreTexto(arvore, argv[ARQUIVO], V);

    Libera(arvore);
    LiberaListaArv(lista);

    return 0;
}