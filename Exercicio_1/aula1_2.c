#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define PI 3.14

void calc_esfera(float r, float *area, float *volume)
{
    float area_, volume_;

    area_ = 4 * PI * r * r;
    volume_ = (4 * PI * r * r * r) / 3;

    *area = area_;
    *volume = volume_;
}

/* Main para a função calc_esfera
int main()
{
    float raio;

    float *area = malloc(sizeof(float));
    float *volume = malloc(sizeof(float));

    printf("Forneca o raio: ");

    scanf("%f", &raio);

    calc_esfera(raio, area, volume);

    printf("Area = %.2f\n", *area);
    printf("Volume = %.2f\n", *volume);


    return 0;
}
*/

int raizes(float a, float b, float c, float *x1, float *x2)
{
    float result, delta, result_x1, result_x2;

    delta = (b * b) - (4 * (a * c));

    if (delta < 0)
        return -1;

    result_x1 = ((-1 * b) + sqrt(delta)) / 2 * a;
    result_x2 = ((-1 * b) - sqrt(delta)) / 2 * a;

    *x1 = result_x1;
    *x2 = result_x2;

    return 1;
}

/* Main para a função raizes
int main()
{
    float a, b, c;

    float *x1 = malloc(sizeof(float));
    float *x2 = malloc(sizeof(float));

    printf("Forneca os dados de a, b, c da equacao de segundo grau: ");

    scanf("%f %f %f", &a, &b, &c);

    if (raizes(a, b, c, x1, x2) < 0)
    {
        printf("Nao existe valores para x1 e x2\n");
    }

    else
    {
        printf("Os valores de x1 e x2 sao: %.2f %.2f\n", *x1, *x2);
    }

    return 0;
}
*/

int pares(int n, int *vet)
{
    int result = 0;

    for (int i = 0; i < n; i++)
    {
        if (vet[i] % 2 == 0)
        {
            result++;
        }
    }

    return result;
}

/* Main para a função pares
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

    n = pares(n, vet);

    printf("Existem %d numeros pares no vetor\n", n);

    return 0;
}
*/

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
        for (int i = 0; i < ((n - 1) / 2); i++)
        {
            aux = vet[inverso];
            vet[inverso] = vet[i];
            vet[i] = aux;
            inverso--;
        }
    }
}

/* Main para a função inverte
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
*/

double avalia(double *poli, int grau, double x)
{
    double result = 0, conta = 0;

    for (int i = 0; i <= grau; i++)
    {
        if (i == 0)
        {
            result += poli[i];
        }

        else
        {
            conta = poli[i] * pow(x, i);
            result += conta;
        }
    }

    return result;
}

/* Main para a função avalia
int main()
{
    int grau;
    double n, x;

    printf("Digite o grau do seu polinômio: ");

    scanf("%d", &grau);

    printf("Digite o valor de x: ");

    scanf("%lf", &x);

    double *poli = malloc(sizeof(double) * grau);

    for (int i = 0; i < grau; i++)
    {
        printf("Digite o numero da posicao %d: ", i);
        scanf("%lf", &n);

        poli[i] = n;
    }

    n = avalia(poli, grau, x);

    printf("A avaliação é:  %.2lf\n", n);

    return 0;
}
*/