#include "listaLikes.h"

typedef struct Celula tCelula;

struct Celula
{
    tLike *like;
    tCelula *prox;
};

struct LikeLista
{
    tCelula *inicio;
    tCelula *fim;
}

tLikeLista *CriaLikeLista()
{
    tLikeLista *likes = malloc(sizeof(tLikeLista));
}