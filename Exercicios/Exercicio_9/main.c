#include <stdlib.h>
#include <stdio.h>
#include "pilha.h"
#include "livro.h"
#include "fila.h"

int main()
{
    int qtd = 0;
    char lixo;

    tLivro *livro;

    printf("Digite a quantidade de livros que serao colocados na pilha: ");

    scanf("%d%c", &qtd, &lixo);

    tFila *fila = InicializaFila(qtd);

    for (int i = 0; i < qtd; i++)
    {
        livro = CriaLivro();

        InsereLivroFila(fila, livro);
    }

    livro = RetiraLivroFila(fila, qtd);

    //LiberaLivro(livro);

    ImprimeFila(fila, qtd);

    LiberaFila(fila);

    return 0;
}