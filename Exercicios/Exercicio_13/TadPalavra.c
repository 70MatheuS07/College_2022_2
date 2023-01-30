#include "TadPalavra.h"

struct Palavra
{
    char *string;
    int qtd;
    tPalavra *prox;
};

tPalavra *InicializaPalavra(char *string)
{
    tPalavra *palavra = malloc(sizeof(tPalavra));

    palavra->string = strdup(string);
    palavra->qtd = 0;
    palavra->prox = NULL;

    return palavra;
}

char *RetornaStringPalavra(tPalavra *palavra)
{
    return palavra->string;
}

void AtualizaQuantidadeOcorrencias(tPalavra *palavra)
{
    palavra->qtd++;
}

int RetornaOcorrencias(tPalavra *palavra)
{
    return palavra->qtd;
}

void LiberaPalavra(tPalavra *palavra)
{
    free(palavra->string);
    palavra->string = NULL;

    free(palavra);
}