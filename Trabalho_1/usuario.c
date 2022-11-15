#include "usuario.h"

struct Usuario
{
    char *nome;
    int idade;
    char *localizacao;
    tListaHobby *hobbies;
    tListaLike *likes;
    tPackage *package;
};

tUsuario *CriaUsuario()
{
    tUsuario *usuario = malloc(sizeof(tUsuario));

    // Inserir tListaLike e tListaAmigo: malloc neles

    usuario->likes = CriaListaLike();

    return usuario;
}

tUsuario *ColetaUsuario(FILE *arquivo)
{
    int idade;

    tUsuario *usuario = CriaUsuario();

    char *nome = malloc(101 * sizeof(char));

    fscanf(arquivo, "%100[^;]", nome);

    char *string = strdup(nome);

    usuario->nome = string;
    string = NULL;

    free(nome);
    nome = NULL;

    fscanf(arquivo, ";%d;", &idade);

    usuario->idade = idade;

    char *localizacao = malloc(101 * sizeof(char));

    fscanf(arquivo, "%100[^;]", localizacao);

    string = strdup(localizacao);

    usuario->localizacao = string;
    string = NULL;

    free(localizacao);
    localizacao = NULL;

    fscanf(arquivo, ";");

    usuario->hobbies = ColetaHobbyLista(arquivo);

    return usuario;
}

void ImprimeUsuario(tUsuario *usuario)
{
    printf("Nome: %s\n", usuario->nome);
    printf("Idade: %d\n", usuario->idade);
    printf("Localizacao: %s\n", usuario->localizacao);

    ImprimeListaHobby(usuario->hobbies);

    // Passar o 2 por parametro (argv)
    ImprimePackage(usuario->package, 2);
}

void LiberaUsuario(tUsuario *usuario)
{
    free(usuario->nome);
    usuario->nome = NULL;

    free(usuario->localizacao);
    usuario->localizacao = NULL;

    LiberaListaHobby(usuario->hobbies);

    LiberaPackage(usuario->package);

    LiberaListaLikeEdMatch(usuario->likes);

    free(usuario);
    usuario = NULL;
}

void LehPackageUsuario(tUsuario *usuario, int num)
{
    usuario->package = LehPackageArquivo(usuario->nome, usuario->package, num);
}

char *RegistraLikeUsuario(tUsuario *usuario, int i)
{
    tLike *likeUsuario;
    char *nome;

    likeUsuario = RetornaLikePackage(usuario->package, i);

    if (VerificaLike(likeUsuario) == 1)
    {
        nome = RetornaNomeLike(likeUsuario);

        if (nome[0] != '.')
        {
            InsereLikeLista(usuario->likes, likeUsuario);

            return nome;
        }
    }

    return NULL;
}

int ConfereSeNomesSaoIguais(tUsuario *usuario, char *nome)
{
    if (strcmp(usuario->nome, nome) == 0)
    {
        return 1;
    }

    return 0;
}

int GerouAmizadeEntreUsuarios(tUsuario *usuarioAmigo, tUsuario *usuario)
{
    if (ComparaListaLikeNome(usuarioAmigo->likes, usuario->nome) == 1)
    {
        return 1;
    }

    return 0;
}

char *RetornaNomeUsuario(tUsuario *usuario)
{
    return usuario->nome;
}

char *RegistraUnlikeUsuario(tUsuario *usuario, int i)
{
    tLike *unlikeUsuario;
    char *nome;

    unlikeUsuario = RetornaUnlikePackage(usuario->package, i);

    if (VerificaLike(unlikeUsuario) == 1)
    {
        nome = RetornaNomeLike(unlikeUsuario);

        if (nome[0] != '.' && nome != NULL)
        {
            RetiraDaListaLikeEdMatch(usuario->likes, nome);

            return nome;
        }
    }

    return NULL;
}

tListaHobby *RetornaListaHobbyUsuario(tUsuario *usuario)
{
    return usuario->hobbies;
}

tPackage *RetornaPackageUsuario(tUsuario *usuario)
{
    return usuario->package;
}

void RegistraListaHobby(tUsuario *usuario, int num, FILE *arquivo)
{
    tListaHobby *confereDado = usuario->hobbies;

    usuario->hobbies = ConfereModificaHobbiesEdMatch(usuario->hobbies, usuario->package, num);

    if (RetornaCharListaHobby(RetornaListaHobbyPackage(usuario->package, num)) != '.')
    {
        fprintf(arquivo, "! %s mudou seu hobbie para:\n", usuario->nome);

        ImprimeHobbiesEdMatch(usuario->hobbies, arquivo);
    }
}

tListaHobby *ConfereModificaHobbiesEdMatch(tListaHobby *hobbies, tPackage *package, int num)
{
    tListaHobby *hobbiesPackage;

    hobbiesPackage = RetornaListaHobbyPackage(package, num);

    if (ConfereListaHobbyPackage(hobbiesPackage) == 1)
    {
        LiberaListaHobby(hobbies);

        tListaHobby *novo = CriaListaHobby();

        CopiaHobbiesPackageParaHobbies(novo, hobbiesPackage);

        return novo;
    }

    return hobbies;
}

void RegistraPostUsuario(tUsuario *usuario, int num, FILE *arquivo)
{
    if (RetornaPrimeiroCharPost(RetornaPostPackage(usuario->package, num)) != '.')
    {
        fprintf(arquivo, "* %s publicou:\n", usuario->nome);
        fprintf(arquivo, "-> %s\n", RetornaPostPackage(usuario->package, num));
    }
}

char RetornaPrimeiroCharPost(char *post)
{
    return post[0];
}

int UsuarioAmigoTemLike(tUsuario *usuario, tUsuario *amigoUsuario)
{
    char *nome;

    if (ProcuraNomeListaLike(amigoUsuario->likes, usuario->nome) == 1)
    {
        return 1;
    }

    return 0;
}