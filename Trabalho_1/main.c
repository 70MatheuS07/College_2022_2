#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lista.h"

int main(int argc, char *argv[])
{
    tLista *usuarios = CriaLista();

    usuarios = LehUsuariosLista(usuarios);

    ImprimeLista(usuarios);

    //Leh o arquivo de users.txt
    
}