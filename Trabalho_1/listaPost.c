#include "listaPost.h"

typedef struct celula Celula;

struct celula
{

    tPost *post;
    Celula *prox;
};

struct listaPost
{

    Celula *prim;
    Celula *ult;
};

tListaPost *CriaListaPost()
{

    tListaPost *listaPost = malloc(sizeof(tListaPost));

    listaPost->prim = NULL;
    listaPost->ult = NULL;

    return listaPost;
}

void InsereListaPost(tListaPost *listaPost, tPost *post)
{

    Celula *nova = malloc(sizeof(Celula));
    nova->post = post;
    nova->prox = NULL;

    if (listaPost->prim == NULL)
    {
        listaPost->prim = nova;
        listaPost->ult = nova;
    }
    else
    {
        listaPost->ult->prox = nova;
        listaPost->ult = nova;
    }
}

void ImprimeListaPost(tListaPost *listaPost, FILE *arquivo)
{
    fprintf(arquivo, "POSTS PUBLICADOS\n");

    for (Celula *p = listaPost->prim; p != NULL; p = p->prox)
    {
        ImprimePost(p->post, arquivo);
    }

    fprintf(arquivo, "\n");
}

void LiberaListaPost(tListaPost *listaPost)
{
    Celula *t;
    Celula *p = listaPost->prim;

    while (p != NULL)
    {
        t = p->prox;

        LiberaPost(p->post);
        free(p);

        p = t;
    }

    free(listaPost);
}

void CriaInserePostNaLista(tListaPost *listaPost, char *msg, int alcance)
{

    tPost *post = CriaPost(msg, alcance);

    InsereListaPost(listaPost, post);
}