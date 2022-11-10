#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "listaUsuario.h"

int main(int argc, char *argv[])
{
    ///*
    char *string = calloc(2, sizeof(char));
    string = "2\0";
    argv[1] = string;
    argc = 2;
    //*/

    int num = atoi(argv[argc - 1]);

    tListaUsuario *usuarios = CriaListaUsuario();

    usuarios = LehUsuariosLista(usuarios);

    // Todo mundo sem package, comeu com angu
    LehPackageListaUsuario(usuarios, num);

    ImprimeListaUsuario(usuarios);

    LiberaListaUsuario(usuarios);

    return 0;
}