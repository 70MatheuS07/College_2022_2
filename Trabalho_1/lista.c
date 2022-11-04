#include "lista.h"

typedef struct Celula tCelula;

struct Celula
{
    tUsuario *usuario;
    tCelula *prox;
};

struct Lista
{
    tCelula *inicio;
    tCelula *fim;
};

tLista *CriaLista()
{
    tLista *lista = malloc(sizeof(tLista));

    lista->inicio = NULL;
    lista->fim = NULL;

    return lista;
}

tLista *LehUsuariosLista(tLista *lista)
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

    return lista;
}

void InsereUsuarioLista(tLista *lista, tUsuario *usuario)
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

void ImprimeLista(tLista *lista)
{
    for (tCelula *aux = lista->inicio; aux != NULL; aux = aux->prox)
    {
        ImprimeUsuario(aux->usuario);
    }
}