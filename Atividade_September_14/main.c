#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define QTD_INICIAL 8

int VerificaPalindromo(char *palavra, int qtdLetras);

int main()
{
    char *palavra = malloc(sizeof(char) * QTD_INICIAL);
    char letra;
    int qtdLetras = 0, multiplicador = 1, i = 0;

    while (1)
    {
        scanf("%c", &letra);

        if (qtdLetras == QTD_INICIAL * multiplicador)
        {
            multiplicador++;
            palavra = realloc(palavra, sizeof(char *) * (QTD_INICIAL * multiplicador));
        }

        if (letra == '\n')
        {
            palavra[i] = '\0';
            break;
        }

        else
        {
            palavra[i] = letra;
            qtdLetras++;
        }

        i++;
    }

    if (VerificaPalindromo(palavra, qtdLetras) == 1)
    {
        printf("A palavra %s é palindromo\n", palavra);
    }

    else
    {
        printf("A palavra %s não é palindromo\n", palavra);
    }

    return 0;
}

int VerificaPalindromo(char *palavra, int qtdLetras)
{
    int j=0;
    char *palavraInvertida = malloc(sizeof(char) * qtdLetras);

    for (int i = qtdLetras - 1; i >= 0; i--)
    {
        palavraInvertida[j] = palavra[i];
        j++;
    }

    palavraInvertida[j] = '\0';

    if(strcmp(palavra, palavraInvertida) == 0)
    {
        return 1;
    }

    return 0;
}