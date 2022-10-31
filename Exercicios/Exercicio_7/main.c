#include <stdlib.h>
#include <stdio.h>
#include "pilha.h"
#include "livro.h"

#define TAM_PILHA 10

int main()
{
    int qtd = 0;
    char lixo;

    tPilha *pilha = CriaPilha(TAM_PILHA);

    tLivro *livro;

    printf("Digite a quantidade de livros que serao colocados na pilha: ");

    scanf("%d%c", &qtd, &lixo);

    for (int i = 0; i < qtd; i++)
    {
        livro = CriaLivro();

        ColocaLivroPilha(pilha, livro);
    }

    ImprimePilha(pilha);

    livro = RetiraLivroPilha(pilha);
    LiberaLivro(livro);

    ImprimePilha(pilha);

    return 0;
}