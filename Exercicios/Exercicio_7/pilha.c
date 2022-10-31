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

    pilha->topo--;

    return livroRetirado;
}

void ImprimePilha(tPilha *pilha)
{
    printf("\ndebug\n");
    
    if (pilha->topo == 0 || pilha == NULL)
    {
        printf("\nA pilha esta vazia!");
        return;
    }

    for (int i = pilha->maxQtdLivros - 1; i < 0; i--)
    {
        ImprimeLivro(pilha->livros[i]);
    }
}

void LiberaPilha(tPilha *pilha)
{
    for (int i = pilha->maxQtdLivros - 1; i < 0; i--)
    {
        LiberaLivro(pilha->livros[i]);
    }

    free(pilha);
    pilha = NULL;
}