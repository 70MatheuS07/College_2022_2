#include "listaHobby.h"

typedef struct Celula tCelula;

struct Celula
{
    char *hobby;
    tCelula *prox;
};

struct ListaHobby
{
    tCelula *inicio;
    tCelula *fim;
};

tListaHobby *ColetaHobbies(FILE *arquivo)
{
    int i = 0;
    char caracter;

    tListaHobby *hobbies = malloc(sizeof(tListaHobby));

    char *string;

    while (1)
    {
        string = ColetaHobbyArquivo(arquivo);

        int tam = strlen(string);

        caracter = string[tam - 1];
        string[tam - 1] = '\0';

        InsereHobbyLista(hobbies, string);

        if (feof(arquivo) || caracter == '\n')
        {
            break;
        }
    }

    return hobbies;
}

void InsereHobbyLista(tListaHobby *hobbies, char *hobby)
{
    tCelula *nova = malloc(sizeof(tCelula));

    nova->hobby = hobby;
    nova->prox = NULL;

    if (hobbies->inicio == NULL)
    {
        hobbies->inicio = hobbies->fim = nova;
    }

    else
    {
        hobbies->fim->prox = nova;
        hobbies->fim = nova;
    }
}

void ImprimeHobbies(tListaHobby *hobbies)
{
    for (tCelula *aux = hobbies->inicio; aux != NULL; aux = aux->prox)
    {
        printf("%s ", aux->hobby);
    }
}

void LiberaHobbies(tListaHobby *hobbies)
{
    tCelula *aux, *prox;

    aux = hobbies->inicio;

    while (aux != NULL)
    {
        prox = aux->prox;

        free(aux->hobby);
        aux->hobby = NULL;

        free(aux);
        aux = NULL;

        aux = prox;
    }

    free(hobbies);
    hobbies = NULL;
}