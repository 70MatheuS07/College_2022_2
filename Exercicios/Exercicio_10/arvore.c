#include "arvore.h"

struct arv
{
    tAluno *aluno;
    Arv *esquerda;
    Arv *direita;
};

Arv *arv_criavazia(void)
{
    return NULL;
}

Arv *arv_cria(tAluno *aluno, Arv *e, Arv *d)
{
    Arv *arvore = malloc(sizeof(Arv));

    arvore->aluno = aluno;
    arvore->esquerda = e;
    arvore->direita = d;

    return arvore;
}

Arv *arv_libera(Arv *a)
{
    if (!arv_vazia(a))
    {
        arv_libera(a->esquerda); /* libera esquerda */
        arv_libera(a->direita);  /* libera direita */
        free(a);                 /* libera raiz */
    }

    return NULL;
}

int arv_vazia(Arv *a)
{
    if (a == NULL)
    {
        return 1;
    }

    return 0;
}

int arv_pertence(Arv *a, tAluno *aluno)
{
    if (arv_vazia(a) == 1)
    {
        return 0; /* árvore vazia: não encontrou */
    }

    else
    {
        if (strcmp(RetornaNomeAluno(a->aluno), RetornaNomeAluno(aluno)) == 0)
        {
            return 1;
        }

        if (arv_pertence(a->esquerda, aluno) == 1)
        {
            return 1;
        }

        if (arv_pertence(a->direita, aluno) == 1)
        {
            return 1;
        }
    }

    return 0;
}

void arv_imprime(Arv *a)
{
    if (!arv_vazia(a))
    {
        ImprimeAluno(a->aluno);   /* mostra nó */
        arv_imprime(a->esquerda); /* mostra sae */
        arv_imprime(a->direita);  /* mostra sad */
    }
}

Arv *arv_pai(Arv *a, tAluno *aluno)
{
    if (arv_vazia(a))
    {
        return NULL;
    }

    if ((!(arv_vazia(a->esquerda)) && (aluno == a->esquerda->aluno)) || (!(arv_vazia(a->direita)) && (aluno == a->direita->aluno)))
    {
        return a;
    }

    Arv *aux = arv_pai(a->esquerda, aluno);

    if (aux == NULL)
    {
        aux = arv_pai(a->direita, aluno);
    }

    return aux;
}

int folhas(Arv *a)
{
    if (arv_vazia(a))
    {
        return 0;
    }

    if (arv_vazia(a->esquerda) || arv_vazia(a->direita))
    {
        return 1;
    }

    return (folhas(a->esquerda) + folhas(a->direita));
}

int ocorrencias(Arv *a, tAluno *aluno)
{
    if (arv_vazia(a) == 1)
    {
        return 0; /* árvore vazia: não encontrou */
    }

    if (strcmp(RetornaNomeAluno(a->aluno), RetornaNomeAluno(aluno)) == 0)
    {
        return 1;
    }

    return (ocorrencias(a->esquerda, aluno) + ocorrencias(a->direita, aluno));
}

tAluno *info(Arv *a)
{
    if (!arv_vazia(a))
    {
        return a->aluno;
    }

    return NULL;
}