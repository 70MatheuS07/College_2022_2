#include <stdlib.h>
#include <stdio.h>
#include "pilha.h"
#include "livro.h"

int main()
{
    int qtd = 0;
    char lixo;

    tLivro *livro;

    printf("Digite a quantidade de livros que serao colocados na pilha: ");

    scanf("%d%c", &qtd, &lixo);

    tPilha *pilha = CriaPilha(qtd);

    for (int i = 0; i < qtd; i++)
    {
        livro = CriaLivro();

        ColocaLivroPilha(pilha, livro);
    }

    ImprimePilha(pilha);

    livro = RetiraLivroPilha(pilha);
    LiberaLivro(livro);

    ImprimePilha(pilha);

    LiberaPilha(pilha);

    return 0;
}