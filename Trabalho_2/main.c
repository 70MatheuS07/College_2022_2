#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "ListaArv.h"
#include "VetorFreq.h"

#define NUM_ASCII 256  

int main(void)
{
    int V[NUM_ASCII];

    ZeraVetorFreq(V, NUM_ASCII);
    PreencheVetorFreq(V, NUM_ASCII, "arq.txt");
    ImprimeVetorFreq(V, NUM_ASCII);

    ListaArv *lista = IniciaListaArv();

    PreencheListaArvFrequencia(lista, V, NUM_ASCII);

    ImprimeListaArv(lista);

    

    LiberaListaArv(lista);

    return 0;
}