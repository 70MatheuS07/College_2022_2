#include "usuario.h"

struct Usuario
{
    char *nome;
    int idade;
    char *localizacao;
    tHobbies *hobbies;
};

tUsuario *CriaUsuario()
{
    tUsuario *usuario = malloc(sizeof(tUsuario));

    return usuario;
}

tUsuario *ColetaUsuario(FILE *arquivo)
{
    int idade;

    tUsuario *usuario = CriaUsuario();

    char *nome = malloc(101 * sizeof(char));

    fscanf(arquivo, "%100[^;]", nome);

    char *string = malloc((strlen(nome) + 1) * sizeof(char));
    strcpy(string, nome);

    usuario->nome = string;
    string = NULL;

    free(nome);
    nome = NULL;

    fscanf(arquivo, ";%d;", &idade);

    usuario->idade = idade;

    char *localizacao = malloc(101 * sizeof(char));

    fscanf(arquivo, "%100[^;]", localizacao);

    string = malloc((strlen(localizacao) + 1) * sizeof(char));

    strcpy(string, localizacao);

    usuario->localizacao = string;
    string = NULL;

    free(localizacao);
    localizacao = NULL;

    fscanf(arquivo, ";");

    usuario->hobbies = ColetaHobbies(arquivo);

    return usuario;
}

void ImprimeUsuario(tUsuario *usuario)
{
    printf("Nome: %s\n", usuario->nome);
    printf("Idade: %d\n", usuario->idade);
    printf("Localizacao: %s\n", usuario->localizacao);
    
    ImprimeHobbies(usuario->hobbies);
}