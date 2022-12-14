#include <stdlib.h>
#include <stdio.h>
#include "arvore.h"

int main()
{
    tAluno *aluno1 = CriaAluno("Matheus", 22, 50);
    tAluno *aluno2 = CriaAluno("Firmino", 45, 40);
    tAluno *aluno3 = CriaAluno("Joel", 33, 60);
    tAluno *aluno4 = CriaAluno("Zezefa", 57, 30);
    tAluno *aluno5 = CriaAluno("Jubileu", 25, 45);
    tAluno *aluno6 = CriaAluno("Carolina", 23, 55);
    tAluno *aluno7 = CriaAluno("Pericles", 89, 70);

    Arv *arvore = arv_criavazia();

    arvore = InsereAlunoArvore(arvore, aluno7);
    arvore = InsereAlunoArvore(arvore, aluno6);
    arvore = InsereAlunoArvore(arvore, aluno5);
    arvore = InsereAlunoArvore(arvore, aluno4);
    arvore = InsereAlunoArvore(arvore, aluno3);
    arvore = InsereAlunoArvore(arvore, aluno2);
    arvore = InsereAlunoArvore(arvore, aluno1);

    RetiraAlunoArvore(arvore, 40);

    arv_imprime(arvore);

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