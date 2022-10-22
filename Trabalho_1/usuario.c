#include "usuario.h"

struct Usuario
{
    char *nome;
    int idade;
    char **hobbies;
    int qtdHobbies;
};

tUsuario *CriaUsuario()
{
    char nome[101];
    int idade;

    tUsuario *usuario = calloc(1, sizeof(tUsuario));

    usuario->hobbies = malloc(HOBBIES_INICIAL * sizeof(char *));

    scanf("%[^;]", nome);
    usuario->nome = calloc(strlen(nome), sizeof(char));
    strcpy(usuario->nome, nome);

    scanf(";%d;", &idade);
    usuario->idade = idade;

    while (1)
    {
    }
}