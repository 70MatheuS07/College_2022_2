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

    // Pode mudar de acordo com arquivo de entrada
    arquivo = fopen("test4/input/users.txt", "r");

    while (!feof(arquivo))
    {
        usuario = ColetaUsuario(arquivo);

        InsereUsuarioLista(lista, usuario);
        usuario = NULL;
    }

    fclose(arquivo);

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

void ImprimeListaUsuario(tListaUsuario *lista)
{
    for (tCelula *aux = lista->inicio; aux != NULL; aux = aux->prox)
    {
        ImprimeUsuario(aux->usuario);
        printf("\n\n");
    }
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
                ConfereAmizadeDesfeita(usuarios, nomeUnlike, aux->usuario, arquivo);
            }

            RegistraListaHobby(aux->usuario, i, arquivo);

            RegistraPostUsuario(aux->usuario, i, arquivo);
        }
    }

    fclose(arquivo);
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
            }
        }
    }
}