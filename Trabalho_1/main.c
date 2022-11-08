#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "listaUsuario.h"

int main(int argc, char *argv[])
{
    tListaUsuario *usuarios = CriaLista();

    usuarios = LehUsuariosLista(usuarios);

    LehPackageListaUsuario(usuarios, argc, argv);

    ImprimeLista(usuarios);

    LiberaLista(usuarios);

    return 0;
}