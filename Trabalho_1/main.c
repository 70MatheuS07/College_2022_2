#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "listaUsuario.h"

int main(int argc, char *argv[])
{
    /*
    argv[1] = strdup("2\0");
    argc++;
    */

    int num = atoi(argv[argc - 1]);

    tListaUsuario *usuarios = CriaListaUsuario();

    usuarios = LehUsuariosLista(usuarios);

    LehPackageListaUsuario(usuarios, num);

    ExecutaEdMatch(usuarios, num);

    ImprimeListaUsuario(usuarios, num);

    LiberaListaUsuario(usuarios);

    return 0;
}