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

    // lista = RetiraLista(lista, 10);
    // lista = RetiraLista(lista, 120);
    // lista = RetiraLista(lista, 100);

    ImprimeLista(lista);

    QualMinhaTaxa(lista, 10);
    QualMinhaTaxa(lista, 120);
    QualMinhaTaxa(lista, 100);

    LiberaListaToda(lista);

    return 0;
}