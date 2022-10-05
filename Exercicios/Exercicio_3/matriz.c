#include "matriz.h"

struct matriz
{
    int **matriz;
    int colunas;
    int linhas;
};

Matriz *inicializaMatriz(int nlinhas, int ncolunas)
{
    Matriz *matriz = malloc(1 * sizeof(Matriz));

    matriz->matriz = malloc(nlinhas * sizeof(int *));

    for (int i = 0; i < nlinhas; i++)
    {
        matriz->matriz[i] = malloc(ncolunas * sizeof(int));
    }

    matriz->colunas = ncolunas;
    matriz->linhas = nlinhas;

    return matriz;
}

void modificaElemento(Matriz *mat, int linha, int coluna, int elem)
{
    mat->matriz[linha][coluna] = elem;
}

int recuperaElemento(Matriz *mat, int linha, int coluna)
{
    int elemento;

    elemento = mat->matriz[linha][coluna];

    return elemento;
}

int recuperaNColunas(Matriz *mat)
{
    int numeroColunas;

    numeroColunas = mat->colunas;

    return numeroColunas;
}

int recuperaNLinhas(Matriz *mat)
{
    int numeroLinhas;

    numeroLinhas = mat->linhas;

    return numeroLinhas;
}

Matriz *transposta(Matriz *mat)
{
    Matriz *matrizTransposta = inicializaMatriz(mat->colunas, mat->linhas);

    for (int i = 0; i < matrizTransposta->linhas; i++)
    {
        for (int j = 0; j < matrizTransposta->colunas; j++)
        {
            matrizTransposta->matriz[i][j] = mat->matriz[j][i];
        }
    }

    return matrizTransposta;
}

Matriz *multiplicacao(Matriz *mat1, Matriz *mat2)
{
    Matriz *matrizResult = inicializaMatriz(mat1->linhas, mat1->colunas);
    int result = 0;

    for (int i = 0; i < mat1->linhas; i++)
    {
        for (int j = 0; j < mat1->colunas; j++)
        {
            result += mat1->matriz[i][j] * mat2->matriz[j][i];

            if (j == mat1->colunas - 1)
            {
                matrizResult->matriz[i][j] = result;
                result = 0;
            }
        }
    }
}

void imprimeMatriz(Matriz *mat)
{
    for (int i = 0; i < mat->linhas; i++)
    {
        for (int j = 0; j < mat->colunas; j++)
        {
            printf("%d", mat->matriz[i][j]);

            if (j < mat->colunas - 1)
            {
                printf(" ");
            }
        }

        printf("\n");
    }
}

void destroiMatriz(Matriz *mat)
{
    for (int i = 0; i < mat->linhas; i++)
    {
        free(mat->matriz[i]);
        mat->matriz[i] = NULL;
    }

    free(mat->matriz);
    mat->matriz = NULL;

    free(mat);
    mat = NULL;
}