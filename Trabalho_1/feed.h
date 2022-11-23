#ifndef FEED_H
#define FEED_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct Feed tFeed;

tFeed *CriaFeed(char *nome, char *mensagem);

void LiberaFeed(tFeed *feed);

void ImprimeFeed(tFeed *feed, FILE *arquivo);

#endif