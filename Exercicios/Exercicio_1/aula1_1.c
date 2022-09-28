#include <stdlib.h>
#include <stdio.h>

typedef struct Valor
{
    int x;
    int y;
    int z;
    int w;

} tValor;

typedef struct Ponto
{
    int *px;
    int *py;
    int *pz;
    int *pw;

} tPonto;

void InicializaValores(tValor *valores);

void InicializaPontos(tPonto *pontos, tValor *valores);

void ModificaPonto(char ponto, int valor, tPonto *pontos, tValor *valores);

void ImprimePontos(tPonto *pontos);

void LiberaValores(tValor *valores);

void LiberaPontos(tPonto *pontos);

int main()
{
    tValor *valores = malloc(sizeof(tValor));
    tPonto *pontos = malloc(sizeof(tPonto));
    ;

    InicializaValores(valores);
    InicializaPontos(pontos, valores);

    int valor = 0;
    char ponto;

    printf("Pontos:\n");
    printf("x, y, z e w\n\n");
    printf("Digite o valor e o ponto que deseja alterar: ");
    scanf("%d %c", &valor, &ponto);

    ModificaPonto(ponto, valor, pontos, valores);

    ImprimePontos(pontos);

    LiberaValores(valores);

    LiberaPontos(pontos);

    return 0;
}

void InicializaValores(tValor *valores)
{
    valores->x = 0;
    valores->y = 0;
    valores->z = 0;
    valores->w = 0;
}

void InicializaPontos(tPonto *pontos, tValor *valores)

{
    pontos->px = &valores->x;
    pontos->py = &valores->y;
    pontos->pz = &valores->z;
    pontos->pw = &valores->w;
}

void ModificaPonto(char ponto, int valor, tPonto *pontos, tValor *valores)
{
    switch (ponto)
    {
    case 'x':
        *pontos->px = valor;
        break;

    case 'y':
        *pontos->py = valor;
        break;

    case 'z':
        *pontos->pz = valor;
        break;

    case 'w':
        *pontos->pw = valor;
        break;
    }
}

void ImprimePontos(tPonto *pontos)
{
    printf("x = %d\n", *pontos->px);
    printf("y = %d\n", *pontos->py);
    printf("z = %d\n", *pontos->pz);
    printf("w = %d\n", *pontos->pw);
}

void LiberaValores(tValor *valores)
{
    free(valores);
    valores = NULL;
}

void LiberaPontos(tPonto *pontos)
{
    free(pontos);
    pontos = NULL;
}