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
        if (identificador == 'A')
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

    // ImprimeListaGenerica(lista);

    fclose(arquivo);
    free(nomeArquivo);

    FILE *arquivoSaida = fopen("saida.txt", "w");

    ImpressaoSelecionadaArquivo(lista, PROFESSOR, arquivoSaida);
    fprintf(arquivoSaida, "Salario medio dos professores: %.2f\n\n", CalculoSelecionado(lista, PROFESSOR));

    ImpressaoSelecionadaArquivo(lista, ALUNO, arquivoSaida);
    fprintf(arquivoSaida, "Cr medio dos alunos: %.2f\n\n", CalculoSelecionado(lista, ALUNO));

    fclose(arquivoSaida);
    return 0;
}