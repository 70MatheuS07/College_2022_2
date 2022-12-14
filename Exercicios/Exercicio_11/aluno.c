#include "aluno.h"

struct Aluno
{
    char *nome;
    int idade;
    int matricula;
};

tAluno *CriaAluno(char *nome, int idade, int matricula)
{
    tAluno *aluno = malloc(sizeof(tAluno));

    aluno->nome = strdup(nome);
    aluno->idade = idade;
    aluno->matricula = matricula;

    return aluno;
}

char *RetornaNomeAluno(tAluno *aluno)
{
    return aluno->nome;
}

void ImprimeAluno(tAluno *aluno)
{
    printf("Aluno: %s, idade: %d e matricula: %d\n",
           aluno->nome, aluno->idade, aluno->matricula);
}

void LiberaAluno(tAluno *aluno)
{
    free(aluno->nome);
    free(aluno);
}

int RetornaMatriculaAluno(tAluno *aluno)
{
    return aluno->matricula;
}