#include "amigo.h"

struct Amigo
{
    char *nome;
};

tAmigo *CriaAmigo(char *nome)
{
    tAmigo *amigo = malloc(sizeof(tAmigo));

    amigo->nome = nome;

    return amigo;
}

void LiberaAmigo(tAmigo *amigo)
{
    amigo->nome = NULL;

    free(amigo);
    amigo = NULL;
}

int EhNomeAmigoIgual(tAmigo *amigo, char *nome)
{
    if (strcmp(amigo->nome, nome))
    {
        return 1;
    }

    return 0;
}

void ImprimeAmigo(tAmigo *amigo)
{
    printf("Amigo: %s\n", amigo->nome);
}