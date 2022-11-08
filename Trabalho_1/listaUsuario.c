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

tListaUsuario *CriaLista()
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

    arquivo = fopen("caso_01/entradas/users.txt", "r");

    while (!feof(arquivo))
    {
        usuario = ColetaUsuario(arquivo);

        InsereUsuarioLista(lista, usuario);
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

void ImprimeLista(tListaUsuario *lista)
{
    for (tCelula *aux = lista->inicio; aux != NULL; aux = aux->prox)
    {
        ImprimeUsuario(aux->usuario);
        printf("\n\n");
    }
}

void LiberaLista(tListaUsuario *lista)
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

void LehPackageListaUsuario(tListaUsuario *usuarios, int argc, char *argv[])
{
    for(tCelula *aux = usuarios->inicio; aux != NULL; aux = aux->prox)
    {
        LehPackageUsuario(aux->usuario, argc, argv);
    }
}