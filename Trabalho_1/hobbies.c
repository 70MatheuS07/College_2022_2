#include "hobbies.h"

typedef struct Celula tCelula;

struct Celula
{
    char *hobby;
    tCelula *prox;
};

struct Hobbies
{
    tCelula *primeira;
    tCelula *ultima;
};

tHobbies *ColetaHobbies(FILE *arquivo)
{
    tHobbies *hobbies = malloc(sizeof(tHobbies));

    tCelula *primeiro;

    primeiro->hobby = LehCaracterCaracter(arquivo);
}

char *LehCaracterCaracter(FILE *arquivo)
{
    int i = 0;
    char caracter;

    char *string = malloc(101 * sizeof(char));

    while (1)
    {
        fscanf(arquivo, "%c", &caracter);

        if (caracter == ';' || caracter == '\n')
        {
            string[i] = '\0';
            break;
        }

        else
        {
            string[i] = caracter;
        }

        i++;
    }

    char *result = malloc((strlen(string) + 1) * sizeof(char));

    strcpy(result, string);

    free(string);
    string = NULL;

    return result;
}