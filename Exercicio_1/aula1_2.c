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

int raizes(float a, float b, float c, float *x1, float *x2)
{
    float result, delta, result_x1, result_x2;

    delta = (b * b) - (4 * a * c);

    if (delta < 0)
        return -1;

    result_x1 = ((-1 * b) + sqrt(delta)) / 2 * a;
    result_x2 = ((-1 * b) - sqrt(delta)) / 2 * a;

    *x1 = result_x1;
    *x2 = result_x2;

    return 1;
}

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
        }
    }
}

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
}