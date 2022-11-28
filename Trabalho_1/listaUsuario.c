#include "listaUsuario.h"

typedef struct Celula tCelula;

struct Celula
{
    tUsuario *usuario;
    tCelula *prox;
};

struct ListaUsuario
{
    tCelula *inicio;
    tCelula *fim;
};

tListaUsuario *CriaListaUsuario()
{
    tListaUsuario *lista = malloc(sizeof(tListaUsuario));

    lista->inicio = NULL;
    lista->fim = NULL;

    return lista;
}

tListaUsuario *LehUsuariosLista(tListaUsuario *lista)
{
    int i = 0;

    tUsuario *usuario;

    FILE *arquivo;

    char *leitura = calloc(101, sizeof(char));
    char *teste = strdup(TESTE);
    char *posfixo = strdup("/input/users.txt");

    strcat(leitura, teste);
    strcat(leitura, posfixo);

    arquivo = fopen(leitura, "r");

    while (!feof(arquivo))
    {
        usuario = ColetaUsuario(arquivo);

        InsereUsuarioLista(lista, usuario);
        usuario = NULL;
    }

    fclose(arquivo);

    free(leitura);
    leitura = NULL;

    free(posfixo);
    posfixo = NULL;

    free(teste);
    teste = NULL;

    return lista;
}

void InsereUsuarioLista(tListaUsuario *lista, tUsuario *usuario)
{
    tCelula *nova = malloc(sizeof(tCelula));

    nova->usuario = usuario;
    nova->prox = NULL;

    if (lista->inicio == NULL)
    {
        lista->inicio = lista->fim = nova;
    }

    else
    {
        lista->fim->prox = nova;
        lista->fim = nova;
    }
}

void ImprimeListaUsuario(tListaUsuario *lista, int num)
{
    FILE *arquivo = fopen("reports.txt", "a");

    for (tCelula *aux = lista->inicio; aux != NULL; aux = aux->prox)
    {
        fprintf(arquivo, "====================\n");

        ImprimeUsuario(aux->usuario, num, arquivo);

        ImprimeListaHobby(RetornaListaHobbyUsuario(aux->usuario), arquivo);

        ImprimeListaPost(RetornaListaPostUsuario(aux->usuario), arquivo);

        ImprimeListaFeed(RetornaListaFeedUsuario(aux->usuario), arquivo);

        ImprimeListaAmigo(RetornaListaAmigoUsuario(aux->usuario), arquivo);

        ImprimeListaAmigoSugestoes(RetornaListaAmigoSugestoesUsuario(aux->usuario), arquivo);
    }

    fclose(arquivo);
}

void LiberaListaUsuario(tListaUsuario *lista)
{
    tCelula *aux, *prox;

    aux = lista->inicio;

    while (aux != NULL)
    {
        prox = aux->prox;

        LiberaUsuario(aux->usuario);

        free(aux);
        aux = NULL;

        aux = prox;
    }

    free(lista);
    lista = NULL;
}

void LehPackageListaUsuario(tListaUsuario *usuarios, int num)
{
    for (tCelula *aux = usuarios->inicio; aux != NULL; aux = aux->prox)
    {
        LehPackageUsuario(aux->usuario, num);
    }
}

void ExecutaEdMatch(tListaUsuario *usuarios, int num)
{
    char *nomeLike;
    char *nomeUnlike;

    FILE *arquivo = fopen("logs.txt", "a");

    for (int i = 0; i < num; i++)
    {
        for (tCelula *aux = usuarios->inicio; aux != NULL; aux = aux->prox)
        {
            nomeLike = RegistraLikeUsuario(aux->usuario, i);

            if (nomeLike != NULL)
            {
                fprintf(arquivo, "+ %s curtiu %s\n", RetornaNomeUsuario(aux->usuario), nomeLike);
                  
                ConfereAmizadeFeita(usuarios, nomeLike, aux->usuario, arquivo);
                  
            }

            nomeUnlike = RegistraUnlikeUsuario(aux->usuario, i);

            if (nomeUnlike != NULL)
            {
                fprintf(arquivo, "_ %s descurtiu %s\n", RetornaNomeUsuario(aux->usuario), nomeUnlike);

                if(RetiraDaListaLikeUsuario(aux->usuario, nomeUnlike) == 1){
                  
                    ConfereAmizadeDesfeita(usuarios, nomeUnlike, aux->usuario, arquivo);
                }

            }

            RegistraListaHobby(aux->usuario, i, arquivo);

            RegistraPostFeedListaUsuario(usuarios, aux->usuario, i, arquivo);
        }
    }

    RegistraSugestoesAmizadesListaUsuario(usuarios);

    fclose(arquivo);
}

void RegistraPostFeedListaUsuario(tListaUsuario *listaUsuario, tUsuario *usuario, int num, FILE *arquivo)
{
    if (RetornaPrimeiroCharPost(RetornaPostPackage(RetornaPackageUsuario(usuario), num)) != '.')
    {
        fprintf(arquivo, "* %s publicou:\n", RetornaNomeUsuario(usuario));
        fprintf(arquivo, "-> %s\n", RetornaPostPackage(RetornaPackageUsuario(usuario), num));
        // adicao
        char *msg = RetornaPostPackage(RetornaPackageUsuario(usuario), num);
        CriaInserePostNaLista(RetornaListaPostUsuario(usuario), msg, RetornaNumeroDeAmigos(RetornaListaAmigoUsuario(usuario)));

        if (RetornaNumeroDeAmigos(RetornaListaAmigoUsuario(usuario)) > 0)
        {
            MandaFeedParaListaAmigo(listaUsuario, RetornaListaAmigoUsuario(usuario), RetornaNomeUsuario(usuario), msg);
        }
    }
}

void ConfereAmizadeFeita(tListaUsuario *usuarios, char *nome, tUsuario *usuario, FILE *arquivo)
{
    for (tCelula *aux = usuarios->inicio; aux != NULL; aux = aux->prox)
    {
        if (ConfereSeNomesSaoIguais(aux->usuario, nome) == 1)
        {
            if (GerouAmizadeEntreUsuarios(aux->usuario, usuario) == 1)
            {
                fprintf(arquivo, "# %s e %s viraram amigos\n", RetornaNomeUsuario(usuario), nome);

                // adicao

                CriaAmizadeListaAmigoUsuario(usuario, RetornaNomeUsuario(aux->usuario));
                CriaAmizadeListaAmigoUsuario(aux->usuario, RetornaNomeUsuario(usuario));
            }
        }
    }
}

void ConfereAmizadeDesfeita(tListaUsuario *usuarios, char *nome, tUsuario *usuario, FILE *arquivo)
{
    for (tCelula *aux = usuarios->inicio; aux != NULL; aux = aux->prox)
    {
        if (ConfereSeNomesSaoIguais(aux->usuario, nome) == 1)
        {
            if (GerouAmizadeEntreUsuarios(aux->usuario, usuario) == 1 && UsuarioAmigoTemLike(usuario, aux->usuario) == 1)
            {
                fprintf(arquivo, "$ %s desfez amizade com %s\n", RetornaNomeUsuario(usuario), nome);

                // adicao

                RetiraAmizadeListaAmigoUsuario(usuario, RetornaNomeUsuario(aux->usuario));
                RetiraAmizadeListaAmigoUsuario(aux->usuario, RetornaNomeUsuario(usuario));
            }
        }
    }
}

void MandaFeedParaListaAmigo(tListaUsuario *listaUsuario, tListaAmigo *listaAmigo, char *nome, char *mensagem)
{
    tUsuario *usuario;

    for (tCelula *aux = listaUsuario->inicio; aux != NULL; aux = aux->prox)
    {
        if (NomeUsuarioIgualNomeAmigo(listaAmigo, RetornaNomeUsuario(aux->usuario)) == 0)
        {
            EnviaNomeMensagemParaListaFeedUsuarioAmigo(aux->usuario, nome, mensagem);
        }
    }
}

void RegistraSugestoesAmizadesListaUsuario(tListaUsuario *usuarios)
{
    for (tCelula *aux1 = usuarios->inicio; aux1 != NULL; aux1 = aux1->prox)
    {
        for (tCelula *aux2 = usuarios->inicio; aux2 != NULL; aux2 = aux2->prox)
        {
            if (ConfereUsuariosNomesDiferentes(aux1->usuario, aux2->usuario) == 1)
            {
                if (strcmp(RetornaLocalizacaoUsuario(aux1->usuario), RetornaLocalizacaoUsuario(aux2->usuario)) == 0)
                {
                    if (RetornaDiferencaIdadesUsuarios(aux1->usuario, aux2->usuario) <= DIFERENCA_IDADE_MAX)
                    {
                        if(ConfereListaAmigoAmizadeUsuarios(aux1->usuario, RetornaNomeUsuario(aux2->usuario)) == 1)
                        {
                            CriaInsereAmigoListaSugestoes(aux1->usuario, RetornaNomeUsuario(aux2->usuario));
                        }
                    }
                }
            }
        }
    }
}