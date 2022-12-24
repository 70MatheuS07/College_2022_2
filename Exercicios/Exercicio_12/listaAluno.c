#include "listaAluno.h"

int ComparaMatriculaCB(void *aluno, void *chave);

int ImprimeCB(void *item, void *dado);

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
    lista->listaGen = InsereItemListaGenerica(lista->listaGen, aluno);

    return lista;
}

tListaAluno *RetiraAlunoListaAluno(tListaAluno *lista, int matricula)
{
    void *numero = &matricula;

    lista->listaGen = RetiraItemListaGenerica(lista->listaGen, ComparaMatriculaCB, numero);

    return lista;
}

void ImprimeListaAluno(tListaAluno *lista)
{
    int n = PercorreListaGenerica(lista->listaGen, ImprimeCB, NULL);
}

int ImprimeCB(void *item, void *dado)
{
    tAluno *aluno = (tAluno *)item;

    ImprimeAluno(aluno);

    return 1;
}

void LiberaListaAluno(tListaAluno *lista)
{
    LiberaListaGenerica(lista->listaGen);
    free(lista);
    lista = NULL;
}

int ComparaMatriculaCB(void *aluno, void *chave)
{
    tAluno *aux1 = (tAluno *)aluno;
    int *aux2 = (int *)chave;

    if (RetornaMatriculaAluno(aux1) == *aux2)
    {
        return 0;
    }

    return 1;
}