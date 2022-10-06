#ifndef CLIENTE_H
#define CLIENTE_H

#include <stdlib.h>
#include <stdio.h>
#include "matriz.h"

typedef struct Cliente tCliente;

tCliente *InicializaCliente();

void ScanfCliente(tCliente *cliente);

void EscolheMatrizTranspostaCliente(tCliente *cliente);

void MultiplicaMatrizesCliente(tCliente *cliente);

void LiberaCliente(tCliente *cliente);

#endif