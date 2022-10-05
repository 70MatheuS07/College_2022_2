#include "cliente.h"

struct Cliente
{
    Matriz *matriz1;
    Matriz *matriz2;
};

tCliente *InicializaCliente()
{
    int nlinhas, ncolunas;

    tCliente *cliente = malloc(sizeof(tCliente));

    printf("Digite o numero de linhas da matriz 1: ");
    scanf("%d", &nlinhas);

    printf("Digite o numero de colunas da matriz 1: ");
    scanf("%d", &ncolunas);

    cliente->matriz1 = inicializaMatriz(nlinhas, ncolunas);

    printf("Digite o numero de linhas da matriz 2: ");
    scanf("%d", &nlinhas);

    printf("Digite o numero de colunas da matriz 2: ");
    scanf("%d", &ncolunas);

    cliente->matriz2 = inicializaMatriz(nlinhas, ncolunas);

    return cliente;
}

void ScanfCliente(tCliente *cliente)
{
    int nlinhas = 0, ncolunas = 0, elemento = 0;

    nlinhas = recuperaNLinhas(cliente->matriz1);
    ncolunas = recuperaNColunas(cliente->matriz1);

    printf("Numeros para a matriz 1:\n\n");

    for (int i = 0; i < nlinhas; i++)
    {
        for (int j = 0; j < ncolunas; j++)
        {
            printf("Insira o elemento da linha %d coluna %d: ", i + 1, j + 1);
            scanf("%d", &elemento);
            modificaElemento(cliente->matriz1, i, j, elemento);
        }
    }

    nlinhas = recuperaNLinhas(cliente->matriz2);
    ncolunas = recuperaNColunas(cliente->matriz2);

    printf("Numeros para a matriz 2:\n\n");

    for (int i = 0; i < nlinhas; i++)
    {
        for (int j = 0; j < ncolunas; j++)
        {
            printf("Insira o elemento da linha %d coluna %d: ", i + 1, j + 1);
            scanf("%d", &elemento);
            modificaElemento(cliente->matriz2, i, j, elemento);
        }
    }
}

void EscolheMatrizTranspostaCliente(tCliente *cliente)
{
    int opcao;
    printf("Opcoes de transposta:\n");
    printf("1- Matriz1\n");
    printf("2- Matriz2\n");

    scanf("%d", &opcao);

    if (opcao == 1)
    {
        imprimeMatriz(transposta(cliente->matriz1));
    }

    else if(opcao == 2)
    {
        imprimeMatriz(transposta(cliente->matriz2));
    }
}

void MultiplicaMatrizesCliente(tCliente *cliente)
{
    imprimeMatriz(multiplicacao(cliente->matriz1, cliente->matriz2));
}

void LiberaCliente(tCliente *cliente)
{
    destroiMatriz(cliente->matriz1);
    destroiMatriz(cliente->matriz2);
}