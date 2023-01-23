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
    // ImprimeVetorFreq(V, NUM_ASCII);

    ListaArv *lista = IniciaListaArv();

    PreencheListaArvFrequencia(lista, V, NUM_ASCII);

    ImprimeListaArv(lista);

    Arv *arvore = CriaArv_Vazia();
    arvore = ExecutaAlgoritimoDeHuffman(lista);

    printf("\n\n");
    Imprime(arvore);
    printf("\n\n");

    // ImprimeListaArv(lista);

    CompactaArvoreTexto(arvore, argv[ARQUIVO]);

    ImprimeListaArv(lista);

    Libera(arvore);
    LiberaListaArv(lista);

    return 0;
}