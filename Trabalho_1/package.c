#include "package.h"

struct Package
{
    tListaLike **likes;
    tListaLike **unlikes;
    tListaHobby **hobbies;
    char **post;
};

tPackage *CriaPackage(int num)
{
    tPackage *package = malloc(sizeof(tPackage));

    package->likes = malloc(num * sizeof(tListaLike *));

    package->unlikes = malloc(num * sizeof(tListaLike *));

    package->hobbies = malloc(num * sizeof(tListaHobby *));

    package->post = malloc(num * sizeof(char *));

    return package;
}

tPackage *LehPackageArquivo(char *nome, tPackage *package, int num)
{
    package = CriaPackage(num);

    char *string = calloc(101, sizeof(char));

    char fixo[13] = ".package.txt";

    char prefixo[101] = "caso_01/entradas/";

    strcpy(string, nome);

    strcat(string, fixo);

    strcat(prefixo, string);

    FILE *arquivo;

    arquivo = fopen(prefixo, "r");

    char *str;
    char caracter = '\0';
    int qtd = 0, i = 0;
    tLike *like;
    tLike *unlike;

    while (feof(arquivo) || num == i)
    {
        package->likes[i] = CriaListaLike();
        package->unlikes[i] = CriaListaLike();
        package->hobbies[i] = CriaListaHobby();

        // Pega likes arquivo
        while (caracter != ';')
        {
            str = LehCaracterCaracterPackage(arquivo);

            qtd = strlen(str);

            caracter = str[qtd - 1];
            str[qtd - 1] = '\0';

            like = CriaLike(str, 1);

            InsereLikeLista(package->likes[i], like);
        }

        // Pega unlikes arquivo;
        while (caracter != ';')
        {
            str = LehCaracterCaracterPackage(arquivo);

            qtd = strlen(str);

            caracter = str[qtd - 1];
            str[qtd - 1] = '\0';

            unlike = CriaLike(str, 0);

            InsereLikeLista(package->likes[i], unlike);
        }

        while (caracter != ';')
        {
            str = LehCaracterCaracterPackage(arquivo);

            qtd = strlen(str);

            caracter = str[qtd - 1];
            str[qtd - 1] = '\0';

            InsereHobbyLista(package->hobbies[i], str);
        }

        while (caracter != '\n' || feof(arquivo))
        {
            str = LehCaracterCaracterPackage(arquivo);

            qtd = strlen(str);

            caracter = str[qtd - 1];

            if (str[qtd - 1] == '\n')
            {
                str[qtd - 1] = '\0';
            }

            package->post[i] = str;
        }

        i++;
    }

    fclose(arquivo);

    return package;
}

char *LehCaracterCaracterPackage(FILE *arquivo)
{
    int i = 0;

    char *string = calloc(101, sizeof(char));
    char caracter;

    while (1)
    {
        fscanf(arquivo, "%c", &caracter);

        if (caracter == ',' || caracter == ';' || caracter == '\n')
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

    char *result = malloc(i + 1 * sizeof(char));

    strcpy(result, string);

    free(string);
    string = NULL;

    return result;
}

void ImprimePackage(tPackage *package, int num)
{
    for (int i = 0; i < num; i++)
    {
        ImprimeListaLike(package->likes[i]);
        ImprimeListaLike(package->unlikes[i]);
        ImprimeListaHobby(package->hobbies[i]);

        printf("post: %s\n", package->post[i]);
    }
}