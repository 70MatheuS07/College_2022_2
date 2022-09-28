#include <stdlib.h>
#include <stdio.h>

#define TAM_INICIAL 4

void OrganizaPointerNumbers(int **pointerNumbers);

int main()
{
    int *numeros = malloc(sizeof(int) * TAM_INICIAL);

    numeros[0] = 10;
    numeros[1] = 20;
    numeros[2] = 5;
    numeros[3] = 2;

    int **pointerNumbers = malloc(sizeof(int *) * TAM_INICIAL);

    for (int i = 0; i < 4; i++)
    {
        pointerNumbers[i] = &numeros[i];
    }

    OrganizaPointerNumbers(pointerNumbers);

    for (int i = 0; i < TAM_INICIAL; i++)
        printf("%d\n", *pointerNumbers[i]);

    return 0;
}

void OrganizaPointerNumbers(int **pointerNumbers)
{
    int *aux;

    for (int i = 0; i < TAM_INICIAL - 1; i++)
    {
        for (int j = 1; j < TAM_INICIAL; j++)
        {
            if (*pointerNumbers[j] < *pointerNumbers[i])
            {
                aux = pointerNumbers[j];

                pointerNumbers[j] = pointerNumbers[i];

                pointerNumbers[i] = aux;
            }
        }

        for (int i = 0; i < TAM_INICIAL; i++)
        {
            printf("%d\n", *pointerNumbers[i]);
        }

        printf("\n");
    }
}