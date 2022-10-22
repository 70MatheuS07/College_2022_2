#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int main()
{
    char string[101];
    char lixo[101];

    scanf("%[^;]", string);

    int num = strlen(string);

    char *nome = calloc(strlen(string), sizeof(char));

    strcpy(nome, string);

    printf("\n%d\n", num);

    printf("\n%s\n", nome);

    scanf(";");

    return 0;
}