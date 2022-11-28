#include "post.h"

struct post
{

    char *msg;
    int alcance;
};

tPost *CriaPost(char *msg, int alcance)
{
    tPost *post = malloc(sizeof(tPost));

    post->msg = msg;
    post->alcance = alcance;

    return post;
}

void ImprimePost(tPost *post, FILE *arquivo)
{
    fprintf(arquivo, "\"%s\" alcance: %d\n", post->msg, post->alcance);
}

void LiberaPost(tPost *post)
{
    free(post);
}