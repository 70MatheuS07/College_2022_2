#include <stdio.h>
#include <stdlib.h>

/*

                   Código escrito por Wagner Gaspar
                   em 26/05/2022
*/

void binario(int n, int *vet, int id)
{
    if (n == 0)
    {
        printf("%d", n);
        vet[id] = n;
    }
    else
    {
        binario(n / 2, vet, id - 1);
        printf("%d", n % 2);
        vet[id] = n % 2;
    }
}

int main()
{
    int i, n, vet[50];

    for (i = 0; i < 50; i++)
        vet[i] = 0;

    printf("Digite um valor decimal: ");
    scanf("%d", &n);

    binario(n, vet, 49);

    printf("\n");
    for (i = 0; i < 50; i++)
        printf("%d", vet[i]);
    printf("\n\n");

    return 0;
}