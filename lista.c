#include "lista.h"

typedef struct Celula tCelula;

struct Celula
{
    union
    {
        Cachorro *cachorro;
        Gato *gato;
    };

    int identificador;
    tCelula *prox;
};

struct Lista
{
    tCelula *inicio;
    tCelula *fim;
};

tLista *CriaLista()
{
    tLista *lista = malloc(sizeof(tLista));

    lista->inicio = NULL;
    lista->fim = NULL;

    return lista;
}

void CadastraGatoLista(tLista *animais, Gato *gato)
{
    tCelula *nova = malloc(sizeof(tCelula));

    nova->gato = gato;
    nova->prox = NULL;
    nova->identificador = GATO;

    if (animais->inicio == NULL)
    {
        animais->inicio = animais->fim = nova;
    }

    else
    {
        animais->fim->prox = nova;
        animais->fim = nova;
    }
}

void CadastraCachorroLista(tLista *animais, Cachorro *cachorro)
{
    tCelula *nova = malloc(sizeof(tCelula));

    nova->cachorro = cachorro;
    nova->prox = NULL;
    nova->identificador = CACHORRO;

    if (animais->inicio == NULL)
    {
        animais->inicio = animais->fim = nova;
    }

    else
    {
        animais->fim->prox = nova;
        animais->fim = nova;
    }
}

void ImprimeLista(tLista *animais)
{
    tCelula *celula;

    for (celula = animais->inicio; celula != NULL; celula = celula->prox)
    {
        if (celula->identificador == CACHORRO)
        {
            imprimeCachorro(celula->cachorro);
        }

        else if (celula->identificador == GATO)
        {
            imprimeGato(celula->gato);
        }
    }
}

float CalculaReceitaLista(tLista *animais)
{
    float valor = 0.0;

    tCelula *celula;

    for (celula = animais->inicio; celula != NULL; celula = celula->prox)
    {
        if (celula->identificador == CACHORRO)
        {
            valor += 40;

            if (retornaNivelAgressividadeCachorro(celula->cachorro) == BRAVO)
            {
                valor += 5;
            }
        }

        else if (celula->identificador == GATO)
        {
            valor += 30;

            if (retornaNivelAgressividadeGato(celula->gato) == BRAVO)
            {
                valor += 5;
            }
        }
    }

    return valor;
}

void LiberaLista(tLista *animais)
{
    tCelula *p = animais->inicio;
    tCelula *t;

    while (p != NULL)
    {
        t = p->prox;

        free(p);
        p = NULL;

        p = t;
    }

    free(animais);
    animais = NULL;
}

void BuscaModificaAnimalLista(tLista *animais, Gato *gato)
{
    
}