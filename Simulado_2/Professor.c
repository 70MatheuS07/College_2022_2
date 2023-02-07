#include "Professor.h"

struct Professor
{
    char *nome;
    int cpf;
    float salario;
    int verificador;
};

tProfessor *CriaLehProfessor(FILE *arquivo)
{
    tProfessor *professor = malloc(sizeof(tProfessor));

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

    float salario = 0.0;
    fscanf(arquivo, "%f\n", &salario);

    professor->nome = nome;
    professor->cpf = cpf;
    professor->salario = salario;
    professor->verificador = PROFESSOR;

    return professor;
}

int RetornaInteiroIdentificador(tProfessor *professor)
{
    return professor->verificador;
}

void ImprimeProfessor(tProfessor *professor, FILE *arquivo)
{
    fprintf(arquivo, "Professor: %s %d %.2f\n", professor->nome, professor->cpf, professor->salario);
}

float RetornaFloatPessoa(tProfessor *professor)
{
    return professor->salario;
}