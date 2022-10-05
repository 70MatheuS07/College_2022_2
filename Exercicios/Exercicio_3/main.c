#include <stdlib.h>
#include <stdio.h>
#include "cliente.h"


int main()
{
    tCliente *cliente = InicializaCliente();

    ScanfCliente(cliente);

    EscolheMatrizTranspostaCliente(cliente);

    MultiplicaMatrizesCliente(cliente);
    
    return 0;
}