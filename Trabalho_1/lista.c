#include "lista.h"

typedef struct Celula tCelula;

struct Celula
{
    tUsuario *usuario;
    tCelula *prox;
};

struct Lista
{
    tCelula *primeira;
    tCelula *ultima;
};

tLista *CriaLista()
{
    tLista *lista = malloc(sizeof(tLista));

    return lista;
}

tLista *LehUsuariosLista(tLista *lista)
{
    tUsuario *usuario;

    FILE *arquivo;

    arquivo = fopen("users.txt", "r");

    while (!feof(arquivo))
    {
        usuario = ColetaUsuario();
    }
}