#include "livro.h"

struct Livro
{
    int id;
    char *nome;
};

tLivro *CriaLivro()
{
    int id;
    char lixo;

    tLivro *livro = malloc(sizeof(tLivro));

    printf("\nDigite o id do livro: ");
    scanf("%d%c", &id, &lixo);
    livro->id = id;

    printf("\nDigite o nome do livro: ");
    livro->nome = LerLinha();

    return livro;
}

void ImprimeLivro(tLivro *livro)
{
    printf("\n\nId do livro: %d", livro->id);

    printf("\nNome do livro: %s", livro->nome);
}

void LiberaLivro(tLivro *livro)
{
    free(livro->nome);
    livro->nome = NULL;

    free(livro);
    livro = NULL;
}