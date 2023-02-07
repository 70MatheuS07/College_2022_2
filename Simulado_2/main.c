#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "ListaGenerica.h"

int main(int argc, char *argv[])
{
    char *nomeArquivo = strdup(argv[1]);

    FILE *arquivo = fopen(nomeArquivo, "r");

    char identificador;

    tAluno *aluno;
    tProfessor *professor;

    tListaGenerica *lista = CriaListaGenerica();

    while (fscanf(arquivo, "%c ", &identificador) != EOF)
    {
        if (identificador == ALUNO)
        {
            aluno = CriaLehAluno(arquivo);
            InserePessoaListaGenerica(lista, aluno);
        }
        else
        {
            professor = CriaLehProfessor(arquivo);
            InserePessoaListaGenerica(lista, professor);
        }
    }

    fclose(arquivo);

    free(nomeArquivo);

    return 0;
}