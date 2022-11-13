#include "package.h"

struct Package
{
    tLike **likes;
    tLike **unlikes;
    tListaHobby **hobbies;
    char **post;
    int num;
};

tPackage *CriaPackage(int num)
{
    tPackage *package = malloc(sizeof(tPackage));

    package->likes = malloc(num * sizeof(tLike *));

    package->unlikes = malloc(num * sizeof(tLike *));

    package->hobbies = malloc(num * sizeof(tListaHobby *));

    package->post = malloc(num * sizeof(char *));

    package->num = num;

    return package;
}

tPackage *LehPackageArquivo(char *nome, tPackage *package, int num)
{
    package = CriaPackage(num);

    FILE *arquivo;

    char *leitura = calloc(101, sizeof(char));
    char *prefixo = calloc(101, sizeof(char));
    char *posfixo = calloc(101, sizeof(char));

    prefixo = "test1/input/\0";
    posfixo = ".package.txt\0";

    ColocaStringNoFimDoCharPointer(leitura, prefixo);
    ColocaStringNoFimDoCharPointer(leitura, nome);
    ColocaStringNoFimDoCharPointer(leitura, posfixo);

    arquivo = fopen(leitura, "r");

    char *string = calloc(101, sizeof(char));
    char *str;
    char caracter = '\0';
    int qtd = 0, i = 0;
    tLike *like;
    tLike *unlike;

    while (i < num)
    {
        package->hobbies[i] = CriaListaHobby();

        // Pega likes arquivo
        fscanf(arquivo, "%[^;]", string);
        fscanf(arquivo, "%c", &caracter);

        // Trocar para strdup(str)! Se sobrar tempo...
        qtd = strlen(string);
        str = malloc((qtd + 1) * sizeof(char));
        strcpy(str, string);

        package->likes[i] = CriaLike(str, 1);

        // Pega unlikes arquivo;
        fscanf(arquivo, "%[^;]", string);
        fscanf(arquivo, "%c", &caracter);

        // Trocar para strdup(str)! Se sobrar tempo...
        qtd = strlen(string);
        str = malloc((qtd + 1) * sizeof(char));
        strcpy(str, string);

        package->unlikes[i] = CriaLike(str, 0);

        caracter = '\0';

        while (caracter != ';')
        {
            str = LehCaracterCaracterPackage(arquivo);

            qtd = strlen(str);

            caracter = str[qtd - 1];
            str[qtd - 1] = '\0';

            InsereHobbyLista(package->hobbies[i], str);
        }

        caracter = '\0';

        while (caracter != '\n')
        {
            if (feof(arquivo))
            {
                break;
            }
            str = LehCaracterCaracterPackagePost(arquivo);

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

    free(string);
    string = NULL;

    free(leitura);
    leitura = NULL;

/* Ta dando erro nao sei como!
    free(prefixo);
    prefixo = NULL;

    free(posfixo);
    posfixo = NULL;
    */

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

char *LehCaracterCaracterPackagePost(FILE *arquivo)
{
    int i = 0;

    char *string = calloc(101, sizeof(char));
    char caracter;

    while (1)
    {
        fscanf(arquivo, "%c", &caracter);

        if (caracter == ';' || caracter == '\n')
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

void ColocaStringNoFimDoCharPointer(char *leitura, char *string)
{
    int i = 0;

    while (1)
    {
        if (leitura[i] == '\0')
        {
            break;
        }

        i++;
    }

    for (int j = 0; string[j] != '\0'; j++)
    {
        leitura[i] = string[j];

        i++;
    }

    leitura[i] = '\0';
}

void ImprimePackage(tPackage *package, int num)
{
    for (int i = 0; i < num; i++)
    {
        ImprimeLike(package->likes[i]);
        ImprimeLike(package->unlikes[i]);
        printf("\n");
        ImprimeListaHobby(package->hobbies[i]);

        printf("post: %s\n", package->post[i]);
    }
}

void LiberaPackage(tPackage *package)
{
    for (int i = 0; i < package->num; i++)
    {
        LiberaLike(package->likes[i]);

        LiberaLike(package->unlikes[i]);

        LiberaListaHobby(package->hobbies[i]);

        free(package->post[i]);
        package->post[i] = NULL;
    }

    free(package->likes);
    package->likes = NULL;

    free(package->unlikes);
    package->unlikes = NULL;

    free(package->hobbies);
    package->hobbies = NULL;

    free(package->post);
    package->post = NULL;

    free(package);
    package = NULL;
}