#include "package.h"

struct Package
{
    tListaLike **likes;
    tListaLike **unlikes;
    tListaHobby **hobbies;
    char **post;
};

tPackage *CriaPackage(int argc, char *argv[])
{
    int qtd = atoi(argv[argc - 1]);

    tPackage *package = malloc(sizeof(tPackage));

    package->likes = malloc(qtd * sizeof(tListaLike *));

    package->unlikes = malloc(qtd * sizeof(tListaLike *));

    package->hobbies = malloc(qtd * sizeof(tListaHobby *));

    package->post = malloc(qtd * sizeof(char *));

    return package;
}

void LehPackageArquivo(char *nome, tPackage *package, int argc, char *argv[])
{
    package = CriaPackage(argc, argv);

    char *string = calloc(101, sizeof(char));

    char fixo[13] = ".package.txt";

    strcpy(string, nome);

    strcat(string, fixo);

    FILE *arquivo;

    arquivo = fopen(string, "r");
}
