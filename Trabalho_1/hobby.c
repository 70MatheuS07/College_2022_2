#include "hobby.h"

struct Hobby
{
    char *nome;
};

char *ColetaHobbyArquivo(FILE *arquivo)
{
    int i = 0;
    char caracter;
    char *string = malloc(101 * sizeof(char));

    while (1)
    {
        fscanf(arquivo, "%c", &caracter);

        if (caracter == ',' || caracter == '\n')
        {
            string[i] = caracter;
            i++;
            string[i] = '\0';
            break;
        }

        else if (feof(arquivo))
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

    char *result = strdup(string);

    free(string);
    string = NULL;

    return result;
}

int NaoTemHobbies(tHobby *hobby)
{
    if (hobby->nome != ".")
    {
        return 1;
    }

    return 0;
}

int EhNomeHobbyIgual(char *hobby, char *nome)
{
    if (strcmp(hobby, nome) == 0)
    {
        return 1;
    }

    return 0;
}

void LiberaHobby(tHobby *hobby)
{
    free(hobby->nome);
    hobby->nome = NULL;

    free(hobby);
    hobby = NULL;
}

char *RetornaNomeHobby(tHobby *hobby)
{
    return hobby->nome;
}