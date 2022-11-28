#include "usuario.h"

struct Usuario
{
    char *nome;
    int idade;
    char *localizacao;
    tListaHobby *hobbies;
    tListaLike *likes;
    tPackage *package;
    // adicao
    tListaAmigo *amigos;
    tListaPost *posts;
    tListaFeed *feed;
    tListaAmigo *sugestoes;
};

tUsuario *CriaUsuario()
{
    tUsuario *usuario = malloc(sizeof(tUsuario));

    // Inserir tListaLike e tListaAmigo: malloc neles

    usuario->likes = CriaListaLike();

    // adicao
    usuario->amigos = CriaListaAmigo();
    usuario->posts = CriaListaPost();
    usuario->feed = CriaListaFeed();
    usuario->sugestoes = CriaListaAmigo();

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

// *************************************************************************************

void ImprimeUsuario(tUsuario *usuario, int num, FILE *arquivo)
{
    fprintf(arquivo, "%s\n", usuario->nome);
    fprintf(arquivo, "%d anos\n", usuario->idade);
    fprintf(arquivo, "%s\n", usuario->localizacao);
    fprintf(arquivo, "%d amigos\n\n", RetornaNumeroDeAmigos(usuario->amigos));
    // ImprimeListaHobby(usuario->hobbies);
    // adicao
    // ImprimeListaAmigo(usuario->amigos);
    // ImprimeListaPost(usuario->posts);

    // Passar o argv.
    // ImprimePackage(usuario->package, num);
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
    // adicao
    LiberaListaAmigo(usuario->amigos);
    LiberaListaPost(usuario->posts);
    LiberaListaFeed(usuario->feed);
    LiberaListaAmigo(usuario->sugestoes);

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

        if (nome[0] != '.')
        {
           // RetiraDaListaLikeEdMatch(usuario->likes, nome);

            return nome;
        }
    }

    return NULL;
}

int RetiraDaListaLikeUsuario(tUsuario *usuario, char* nome){

    return RetiraDaListaLikeEdMatch(usuario->likes, nome);
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

// adicao
void CriaAmizadeListaAmigoUsuario(tUsuario *usuario, char *nome)
{

    CriaInsereAmigoNaLista(usuario->amigos, nome);
}

void RetiraAmizadeListaAmigoUsuario(tUsuario *usuario, char *nome)
{

    RetiraDaListaAmigo(usuario->amigos, nome);
}

tListaPost *RetornaListaPostUsuario(tUsuario *usuario)
{
    return usuario->posts;
}

void EnviaNomeMensagemParaListaFeedUsuarioAmigo(tUsuario *usuario, char *nome, char *mensagem)
{
    ColocaNomeMensagemNaListaFeed(usuario->feed, nome, mensagem);
}

tPackage *RetornaListaPackageUsuario(tUsuario *usuario)
{
    return usuario->package;
}

tListaAmigo *RetornaListaAmigoUsuario(tUsuario *usuario)
{
    return usuario->amigos;
}

tListaFeed *RetornaListaFeedUsuario(tUsuario *usuario)
{
    return usuario->feed;
}

int ConfereUsuariosNomesDiferentes(tUsuario *usuario1, tUsuario *usuario2)
{
    if (strcmp(usuario1->nome, usuario2->nome) == 0)
    {
        return 0;
    }

    return 1;
}

char *RetornaLocalizacaoUsuario(tUsuario *usuario)
{
    return usuario->localizacao;
}

int RetornaDiferencaIdadesUsuarios(tUsuario *usuario1, tUsuario *usuario2)
{
    int result = 0;

    result = usuario1->idade - usuario2->idade;

    if (result < 0)
    {
        result *= -1;
    }

    return result;
}

int ConfereListaAmigoAmizadeUsuarios(tUsuario *usuario, char *nome)
{
    return NomeUsuarioIgualNomeAmigo(usuario->amigos, nome);
}

void CriaInsereAmigoListaSugestoes(tUsuario *usuario, char *nome)
{
    CriaInsereAmigoNaLista(usuario->sugestoes, nome);
}

tListaAmigo *RetornaListaAmigoSugestoesUsuario(tUsuario *usuario)
{
    return usuario->sugestoes;
}