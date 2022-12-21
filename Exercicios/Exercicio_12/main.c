#include <stdlib.h>
#include <stdio.h>
#include "listaAluno.h"

int main()
{
    tAluno *aluno1 = CriaAluno("Matheus", 22, 1001);
    tAluno *aluno2 = CriaAluno("Brother", 45, 1002);
    tAluno *aluno3 = CriaAluno("Joel", 33, 1003);
    tAluno *aluno4 = CriaAluno("Zezefa", 57, 1004);
    tAluno *aluno5 = CriaAluno("Jubileu", 25, 1005);
    tAluno *aluno6 = CriaAluno("Carolina", 23, 1006);
    tAluno *aluno7 = CriaAluno("Pericles", 89, 1007);

    tListaAluno *lista = CriaListaAluno();

    InsereAlunoListaAluno(aluno1);

    return 0;
}