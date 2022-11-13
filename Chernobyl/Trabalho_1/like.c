#include "like.h"

typedef struct Like tLike;

struct Like
{
    char *nomeLike;
    int like;
};

tLike *CriaLike(char *nome, int like)
{
    tLike *l = malloc(sizeof(tLike));
    l->nomeLike = nome;
    l->like = like;

    return l;
}

int EhNomeLikeIgual(tLike *like, char *nome)
{
    if (strcmp(like->nomeLike, nome))
    {
        return 1;
    }
    return 0;
}

void LiberaLike(tLike *like)
{
    like->nomeLike = NULL;

    free(like);
    like = NULL;
}

void ImprimeLike(tLike *like)
{
    printf("\nNome: %s\n", like->nomeLike);

    if (like->like == 1)
    {
        printf("tipo: Like\n");
    }

    else if (like->like == 0)
    {
        printf("tipo: Unlike\n");
    }
}