#include "cliente.h"

struct Cliente
{
    Matriz *matriz1;
    Matriz *matriz2;
    Matriz *matrizTransposta1;
    Matriz *matrizTransposta2;
    Matriz *multiplicacao;
    int verificaMultiplicacao;
};

tCliente *InicializaCliente()
{
    int nlinhas1, ncolunas1;
    int nlinhas2, ncolunas2;

    tCliente *cliente = malloc(1 * sizeof(tCliente));

    printf("Digite o numero de linhas da matriz 1: ");
    scanf("%d", &nlinhas1);

    printf("Digite o numero de colunas da matriz 1: ");
    scanf("%d", &ncolunas1);

    cliente->matriz1 = inicializaMatriz(nlinhas1, ncolunas1);

    printf("Digite o numero de linhas da matriz 2: ");
    scanf("%d", &nlinhas2);

    printf("Digite o numero de colunas da matriz 2: ");
    scanf("%d", &ncolunas2);

    cliente->matriz2 = inicializaMatriz(nlinhas2, ncolunas2);

    cliente->matrizTransposta1 = inicializaMatriz(nlinhas1, ncolunas1);

    cliente->matrizTransposta2 = inicializaMatriz(nlinhas2, ncolunas2);

    if (ncolunas1 == nlinhas2)
    {
        cliente->multiplicacao = inicializaMatriz(nlinhas1, ncolunas2);
        cliente->verificaMultiplicacao = 1;
    }

    else
    {
        cliente->verificaMultiplicacao = 0;
    }

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
        cliente->matrizTransposta1 = transposta(cliente->matriz1);
        imprimeMatriz(cliente->matrizTransposta1);
    }

    else if (opcao == 2)
    {
        cliente->matrizTransposta2 = transposta(cliente->matriz2);
        imprimeMatriz(cliente->matrizTransposta2);
    }
}

void MultiplicaMatrizesCliente(tCliente *cliente)
{
    cliente->multiplicacao = multiplicacao(cliente->matriz1, cliente->matriz2);

    imprimeMatriz(cliente->multiplicacao);
}

void LiberaCliente(tCliente *cliente)
{
    destroiMatriz(cliente->matriz1);

    destroiMatriz(cliente->matriz2);

    destroiMatriz(cliente->matrizTransposta1);

    destroiMatriz(cliente->matrizTransposta2);

    if (cliente->verificaMultiplicacao == 1)
        destroiMatriz(cliente->multiplicacao);

    free(cliente);
    cliente = NULL;
}