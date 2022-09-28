#include <stdlib.h>
#include <stdio.h>

void inverte(int n, int *vet)
{
    int inverso = n - 1, aux = 0;

    if (n % 2 == 0)
    {
        for (int i = 0; i < n / 2; i++)
        {
            aux = vet[inverso];
            vet[inverso] = vet[i];
            vet[i] = aux;
            inverso--;
        }
    }

    else
    {
        for (int i = 0; i < n-1 / 2; i++)
        {
            aux = vet[inverso];
            vet[inverso] = vet[i];
            vet[i] = aux;
            inverso--;
        }
    }
}

int main()
{
    int num;
    int n;

    int *vet = malloc(sizeof(int));

    printf("Digite tamanho do vetor: ");

    scanf("%d", &num);

    for (int i = 0; i < num; i++)
    {
        printf("Digite o numero da posicao %d: ", i);
        scanf("%d", &n);

        vet[i] = n;
    }

    printf("Vetor anterior: ");

    for (int i = 0; i < num; i++)
    {
        if (i == num - 1)
        {
            printf("%d\n", vet[i]);
        }

        else
        {
            printf("%d, ", vet[i]);
        }
    }

    inverte(n, vet);

    printf("Vetor invertido: ");

    for (int i = 0; i < num; i++)
    {
        if (i == num - 1)
        {
            printf("%d\n", vet[i]);
        }

        else
        {
            printf("%d, ", vet[i]);
        }
    }

    return 0;
}
