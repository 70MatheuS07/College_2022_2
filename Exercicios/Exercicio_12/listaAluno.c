#include "listaAluno.h"

struct ListaAluno
{
    tListaGenerica *listaGen;
};

tListaAluno *CriaListaAluno()
{
    tListaAluno *lista = malloc(sizeof(tListaAluno));

    lista->listaGen = CriaListaGenericaVazia();

    return lista;
}

tListaAluno *InsereAlunoListaAluno(tListaAluno *lista, tAluno *aluno)
{
    return InsereItemListaGenerica(lista->listaGen, aluno);
}

void RetiraAlunoListaAluno(tListaAluno *lista, int matricula);
{
    tCelula *aux = lista->inicio;
    tCelula *ant;
    int codigoReturn;

    while (1)
    {
        codigoReturn = RetornaCodigoProduto(aux->produto);

        if (codigoReturn == codigo)
        {
            break;
        }

        if (aux == NULL)
        {
            printf("\nNao existe esse produto para ser retirado");
            return;
        }

        ant = aux;
        aux = aux->prox;
    }

    if (aux == lista->inicio && aux == lista->fim)
    {
        lista->inicio = NULL;
        lista->fim = NULL;

        LiberaProduto(aux->produto);
        aux->prox = NULL;
        free(aux);
        aux = NULL;
    }

    else if (aux == lista->inicio)
    {
        lista->inicio = aux->prox;

        LiberaProduto(aux->produto);
        aux->prox = NULL;
        free(aux);
        aux = NULL;
    }

    else if (aux == lista->fim)
    {
        lista->fim = ant;
        ant->prox = NULL;

        LiberaProduto(aux->produto);
        aux->prox = NULL;
        free(aux);
        aux = NULL;
    }

    else
    {
        ant->prox = aux->prox;
        LiberaProduto(aux->produto);
        aux->prox = NULL;
        free(aux);
        aux = NULL;
    }
}

void ImprimeListaAluno(tListaGenerica *lista)
{
    PercorreListaGenerica(lista, ImprimeCB, NULL);
}

int ImprimeCB(void *item, void *dado)
{
    tAluno *aluno = (tAluno *)item;

    ImprimeAluno(aluno);

    return 1;
}

void LiberaListaAluno(tListaGenerica *lista)
{
    LiberaListaGenerica(lista);
}

int ComparaMatriculaCB(void *aluno, void *chave)
{
    tAluno *aux1 = (tAluno *)aluno;
    int *aux2 = (int *)chave;

    if (RetornaMatriculaAluno(aux1) == &aux2)
    {
        return 0;
    }

    return 1;
}