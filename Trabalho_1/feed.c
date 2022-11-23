#include "feed.h"

struct Feed
{
    char *mensagem;
    char *nome;
};

tFeed *CriaFeed(char *nome, char *mensagem)
{
    tFeed *feed = malloc(sizeof(tFeed));

    feed->nome = nome;
    feed->mensagem = mensagem;

    return feed;
}

void LiberaFeed(tFeed *feed)
{
    feed->nome = NULL;
    feed->mensagem = NULL;

    free(feed);
    feed = NULL;
}

void ImprimeFeed(tFeed *feed, FILE *arquivo)
{
    fprintf(arquivo, "\"%s\" - %s\n", feed->mensagem, feed->nome);
}