#include <stdlib.h>
#include <stdio.h>

int main()
{
    int *numeros = malloc(sizeof(int) * 4);

    numeros[0] = 10;
    numeros[1] = 20;
    numeros[2] = 5;
    numeros[3] = 2;

    int **pointerNumbers = malloc(sizeof(int *) * 4);

    for (int i = 0; i < 4; i++)
    {
        pointerNumbers[i] = &numeros[i];
    }

    //terminar

    return 0;
}