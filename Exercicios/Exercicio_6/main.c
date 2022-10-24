#include <stdlib.h>
#include <stdio.h>
#include "lista.h"

int main()
{
    int qtd = 0;
    tLista *lista = CriaLista();

    scanf("%d\n", &qtd);

    for (int i = 0; i < qtd; i++)
    {
        lista = CriaListaEncadeada(lista);
    }

    ImprimeLista(lista);

    return 0;
}