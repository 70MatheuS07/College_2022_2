#include "arquivo.h"

char *LehNomeArquivoUsers(FILE *arquivo)
{
    char *nome = malloc(101 * sizeof(char));

    fscanf(arquivo, "%100[^;]", nome);

    char *string = malloc((strlen(nome) + 1) * sizeof(char));

    strcpy(string, nome);

    free(nome);
    nome = NULL;

    return string;
}

int LehIdadeArquivoUsers(FILE *arquivo)
{
    int idade;

    fscanf(arquivo, ";%d;", &idade);

    return idade;
}

char *LehLocalizacaoArquivoUsers(FILE*arquivo)
{
    char *localizacao = malloc(101 * sizeof(char));

    fscanf(arquivo, "%100[^;]", localizacao);

    char *string = malloc((strlen(localizacao) + 1) * sizeof(char));

    strcpy(string, localizacao);

    free(localizacao);
    localizacao = NULL;

    return string;
}

char *LehHobbyArquivoUsers(FILE *arquivo)
{
    char *hobby = malloc(101 * sizeof(char));

    fscanf(arquivo, "%100[^,]", hobby);

    char *string = malloc((strlen(hobby) + 1) * sizeof(char));

    strcpy(string, hobby);

    free(hobby);
    hobby = NULL;

    return string;
}