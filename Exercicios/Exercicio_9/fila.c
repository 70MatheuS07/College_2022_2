#include "fila.h"

struct Fila
{
    tPilha *pilha1;
    tPilha *pilha2;
};

tFila *InicializaFila(int tam)
{
    tFila *fila = malloc(sizeof(tFila));

    fila->pilha1 = CriaPilha(tam);
    fila->pilha2 = CriaPilha(tam);

    return fila;
}

tPilha *DevolvePilha1(tFila *fila)
{
    return fila->pilha1;
}

void InsereLivroFila(tFila *fila, tLivro *livro)
{
    printf("\ndebug\n");

    ColocaLivroPilha(fila->pilha1, livro);
}

tLivro *RetiraLivroFila(tFila *fila, int num)
{
    tLivro *livro;

    for (int i = 0; i < num; i++)
    {
        livro = RetiraLivroPilha(fila->pilha1);
        ColocaLivroPilha(fila->pilha2, livro);
    }

    livro = RetiraLivroPilha(fila->pilha2);

    for (int i = 0; i < num; i++)
    {
        livro = RetiraLivroPilha(fila->pilha2);
        ColocaLivroPilha(fila->pilha1, livro);
    }

    return livro;
}

void ImprimeFila(tFila *fila, int num)
{
    tLivro *livro;
    for (int i = 0; i < num; i++)
    {
        livro = RetiraLivroPilha(fila->pilha1);
        ColocaLivroPilha(fila->pilha2, livro);
    }

    ImprimePilha(fila->pilha2);

    for (int i = 0; i < num; i++)
    {
        livro = RetiraLivroPilha(fila->pilha2);
        ColocaLivroPilha(fila->pilha1, livro);
    }
}

void LiberaFila(tFila *fila)
{
    LiberaPilha(fila->pilha1);

    free(fila);
}