#include "hobbies.h"

typedef struct Celula tCelula;

struct Celula
{
    char *hobby;
    tCelula *prox;
};

struct HobbiesLista
{
    tCelula *inicio;
    tCelula *fim;
};

tHobbies *ColetaHobbies(FILE *arquivo)
{
    int i = 0;
    char caracter;

    tHobbies *hobbies = malloc(sizeof(tHobbies));

    char *string;
    char *result;

    while (1)
    {
        string = malloc(101 * sizeof(char));

        while (1)
        {
            fscanf(arquivo, "%c", &caracter);

            if (caracter == ',' || caracter == '\n')
            {
                string[i] = '\0';
                break;
            }

            else
            {
                //da problema na segunda leitura, não sei porque ?
                string[i] = caracter;
            }

            i++;
        }

        result = malloc(i+1 * sizeof(char));

        strcpy(result, string);

        InsereHobbyLista(hobbies, result);

        if (caracter == '\n')
        {
            break;
        }

        free(string);
        string = NULL;

        i = 0;
    }

    free(string);
    string = NULL;

    return hobbies;
}

void InsereHobbyLista(tHobbies *hobbies, char *hobby)
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

void ImprimeHobbies(tHobbies *hobbies)
{
    for (tCelula *aux = hobbies->inicio; aux != NULL; aux = aux->prox)
    {
        printf("%s ", hobbies->inicio->hobby);
    }
}