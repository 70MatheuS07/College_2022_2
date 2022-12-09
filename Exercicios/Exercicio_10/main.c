#include <stdlib.h>
#include <stdio.h>
#include "arvore.h"

int main()
{
    tAluno *aluno1 = CriaAluno("Matheus", 22, 1001);
    tAluno *aluno2 = CriaAluno("Brother", 45, 1002);
    tAluno *aluno3 = CriaAluno("Joel", 33, 1003);
    tAluno *aluno4 = CriaAluno("Zezefa", 57, 1004);
    tAluno *aluno5 = CriaAluno("Jubileu", 25, 1005);
    tAluno *aluno6 = CriaAluno("Carolina", 23, 1006);
    tAluno *aluno7 = CriaAluno("Pericles", 89, 1007);

    Arv *arvore = arv_criavazia();

    arvore = arv_cria(aluno1,
                      (arv_cria(aluno2, arv_cria(aluno4, arv_criavazia(), arv_criavazia()), arv_cria(aluno5, arv_criavazia(), arv_criavazia()))),
                      (arv_cria(aluno3, arv_cria(aluno6, arv_criavazia(), arv_criavazia()), arv_cria(aluno7, arv_criavazia(), arv_criavazia()))));

    ImprimeAluno(info(arv_pai(arvore, aluno4)));

    if (arv_pertence(arvore, aluno1) == 1)
    {
        ImprimeAluno(aluno1);
    }

    int folha = folhas(arvore);
    printf("São %d folhas\n", folha);

    arv_libera(arvore);

    LiberaAluno(aluno1);
    LiberaAluno(aluno2);
    LiberaAluno(aluno3);
    LiberaAluno(aluno4);
    LiberaAluno(aluno5);
    LiberaAluno(aluno6);
    LiberaAluno(aluno7);

    return 0;
}