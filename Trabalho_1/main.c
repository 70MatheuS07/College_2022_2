#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "listaUsuario.h"

int main(int argc, char *argv[])
{
    tListaUsuario *usuarios = CriaLista();

    usuarios = LehUsuariosLista(usuarios);

    ImprimeLista(usuarios);

    LiberaLista(usuarios);
}