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

        else if(feof(arquivo))
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

    char *result = malloc(i + 1 * sizeof(char));

    strcpy(result, string);

    free(string);
    string = NULL;

    return result;
}