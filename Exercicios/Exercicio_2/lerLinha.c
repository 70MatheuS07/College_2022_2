#include "lerLinha.h"

char *LerLinha()
{
    char caracter;
    int num=0;
    char *string = calloc(100, sizeof(char));

    while(1)
    {
        scanf("%c", &caracter);

        if(caracter == '\n')
        {
            string[num] == '\0';
            break;
        }

        else
        {
            string[num] = caracter;
        }

        num++;
    }

    return string;
}