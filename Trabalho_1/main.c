#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "listaUsuario.h"

int main(int argc, char *argv[])
{
    int num = atoi(argv[argc - 1]);

    tListaUsuario *usuarios = CriaListaUsuario();

    usuarios = LehUsuariosLista(usuarios);

    // Todo mundo sem package, comeu com angu
    LehPackageListaUsuario(usuarios, num);

    ImprimeListaUsuario(usuarios);

    LiberaListaUsuario(usuarios);

    return 0;
}