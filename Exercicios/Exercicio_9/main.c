#include <stdlib.h>
#include <stdio.h>
#include "pilha.h"
#include "livro.h"
#include "fila.h"

#define TAM 10

int main()
{
    int qtd = 0;
    char lixo;

    tLivro *livro;

    printf("Digite a quantidade de livros que serao colocados na pilha: ");

    scanf("%d%c", &qtd, &lixo);

    tFila *fila = InicializaFila(TAM);

    for (int i = 0; i < qtd; i++)
    {
        livro = CriaLivro();

        if (livro == NULL)
        {
            break;
        }

        InsereLivroFila(fila, livro);
    }

    // wprintf("\ndebug\n");

    livro = RetiraLivroFila(fila, qtd);

    // LiberaLivro(livro);

    ImprimeFila(fila, qtd);

    LiberaFila(fila);

    return 0;
}