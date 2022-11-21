#include "pilha.h"

struct Pilha
{
    int topo;
    tLivro **livros;
    int maxQtdLivros;
};

tPilha *CriaPilha(int tamanhoPilha)
{
    tPilha *pilha = malloc(sizeof(tPilha));

    pilha->livros = malloc(tamanhoPilha * sizeof(tLivro *));

    pilha->topo = 0;

    pilha->maxQtdLivros = tamanhoPilha;

    return pilha;
}

void ColocaLivroPilha(tPilha *pilha, tLivro *livro)
{
    if (pilha->maxQtdLivros <= pilha->topo)
    {
        printf("\nA pilha de livros esta cheia!");
        return;
    }

    pilha->livros[pilha->topo] = livro;

    pilha->topo++;
}

tLivro *RetiraLivroPilha(tPilha *pilha)
{
    if (pilha->topo == 0)
    {
        printf("\nNao tem livros na pilha");
        return NULL;
    }

    tLivro *livroRetirado = pilha->livros[pilha->topo - 1];

    if (livroRetirado == NULL)
    {
        return NULL;
    }

    pilha->livros[pilha->topo - 1] = NULL;

    pilha->topo--;

    return livroRetirado;
}

void ImprimePilha(tPilha *pilha)
{
    int i = pilha->topo - 1;
    printf("\ndebug\n");

    if (pilha->topo == 0 || pilha == NULL)
    {
        printf("\nA pilha esta vazia!");
        return;
    }

    while (i >= 0)
    {
        ImprimeLivro(pilha->livros[i]);

        i--;
    }

    i = 0;
}

void LiberaPilha(tPilha *pilha)
{
    int i = pilha->topo - 1;

    while (i >= 0)
    {
        LiberaLivro(pilha->livros[i]);
        i--;
    }

    free(pilha->livros);
    pilha->livros = NULL;

    free(pilha);
    pilha = NULL;
}