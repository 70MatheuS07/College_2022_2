#include "usuario.h"

struct Usuario
{
    char *nome;
    int idade;
    tHobbies *hobbies;
    int qtdHobbies;
};

tUsuario *CriaUsuario()
{
    tUsuario *usuario = malloc(sizeof(tUsuario));

    return usuario;
}

tUsuario *ColetaUsuario(FILE *arquivo)
{
    tUsuario *usuario = CriaUsuario();
    
    usuario->nome = LehNomeArquivoUsers(FILE *arquivo);

    usuario->idade = LehIdadeArquivoUsers(FILE *arquivo);

    usuario->hobbies = ColetaHobbies(FILE *arquivo);
}