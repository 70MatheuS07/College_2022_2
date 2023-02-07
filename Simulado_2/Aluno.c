#include "Aluno.h"

struct Aluno
{
    char *nome;
    int cpf;
    float cr;
    int verificador;
};

tAluno *CriaLehAluno(FILE *arquivo)
{
    tAluno *aluno = malloc(sizeof(tAluno));

    char *nome = calloc(100, sizeof(char));
    char caracter;
    int i = 0;

    while (1)
    {
        fscanf(arquivo, "%c", &caracter);

        if (caracter == ' ')
        {
            nome[i] = '\0';
            break;
        }

        nome[i] = caracter;
        i++;
    }

    int cpf = 0;
    fscanf(arquivo, "%d ", &cpf);

    float cr = 0.0;
    fscanf(arquivo, "%f\n", &cr);

    aluno->nome = nome;
    aluno->cpf = cpf;
    aluno->cr = cr;
    aluno->verificador = ALUNO;

    return aluno;
}

void ImprimeAluno(tAluno *aluno, FILE *arquivo)
{
    fprintf(arquivo, "Aluno: %s %d %.2f\n", aluno->nome, aluno->cpf, aluno->cr);
}