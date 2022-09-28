#include "lerLinha.h"

char *LerLinha()
{
    char linha[100];
    scanf(" %99[^\n]", linha);
    return strdup(linha);
}