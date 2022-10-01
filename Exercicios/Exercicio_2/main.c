#include <stdlib.h>
#include <stdio.h>
#include "tSupermercado.h"
#include "tFilial.h"
#include "tEstoque.h"
#include "tProduto.h"

int main()
{
    tSupermercado *supermercado = CriaSupermercado();

    CriaFiliaisSupermercado(supermercado);

    CalculaEstoqueSupermercado(supermercado);

    ImprimeSupermercado(supermercado);
    
    LiberaSupermercado(supermercado);

    return 0;
}