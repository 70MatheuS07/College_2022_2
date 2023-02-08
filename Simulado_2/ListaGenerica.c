#include "ListaGenerica.h"

typedef struct Celula tCelula;

struct Celula
{
    void *pessoa;
    void *identificador;
    tCelula *prox;
};

struct ListaGenerica
{
    tCelula *inicio;
    tCelula *fim;
};

tListaGenerica *CriaListaGenerica()
{
    tListaGenerica *lista = malloc(sizeof(tListaGenerica));

    lista->inicio = NULL;
    lista->fim = NULL;

    return lista;
}

void InserePessoaListaGenerica(tListaGenerica *lista, void *pessoa, void *identificador)
{
    tCelula *nova = malloc(sizeof(tCelula));
    tCelula *ultima;
    nova->pessoa = pessoa;
    nova->identificador = identificador;
    nova->prox = NULL;

    if (lista->inicio == NULL && lista->fim == NULL)
    {
        lista->inicio = nova;
        lista->fim = nova;
    }

    else
    {
        lista->fim->prox = nova;
        lista->fim = nova;
    }
}

void ImpressaoSelecionadaArquivo(tListaGenerica *lista, int identificador, FILE *arquivo)
{
    int id = 0;
    for (tCelula *celula = lista->inicio; celula != NULL; celula = celula->prox)
    {
        id = celula->identificador;

        if (id == identificador)
        {
            ImprimeProfessor(celula->pessoa, arquivo);
        }

        else if (id == identificador)
        {
            ImprimeAluno(celula->pessoa, arquivo);
        }
    }
}

float CalculoSelecionado(tListaGenerica *lista, int identificador)
{
    float parcial = 0, total = 0;
    int id = 0;
    int i = 0;

    for (tCelula *celula = lista->inicio; celula != NULL; celula = celula->prox)
    {
        parcial = RetornaFloatPessoa(celula->pessoa);

        if (id == identificador)
        {
            total += parcial;
            i++;
        }

        else if (id == identificador)
        {
            total += parcial;
            i++;
        }
    }

    return total / i;
}