#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "listaUsuario.h"

int main(int argc, char *argv[])
{
    /*
    char *string = strdup("6");
    argv[1] = string;
    argc = 2;
    */

    int num = atoi(argv[argc - 1]);

    tListaUsuario *usuarios = CriaListaUsuario();

    usuarios = LehUsuariosLista(usuarios);

    LehPackageListaUsuario(usuarios, num);

    ExecutaEdMatch(usuarios, num);

    ImprimeListaUsuario(usuarios);

    LiberaListaUsuario(usuarios);

    //free(string);
    //string = NULL;

    return 0;
}