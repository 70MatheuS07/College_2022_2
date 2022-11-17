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

void CadastraGatoBravoLista(tLista *bravos, Gato *gato)
{
    tCelula *nova = malloc(sizeof(tCelula));

    nova->gato = gato;
    nova->prox = NULL;
    nova->identificador = GATO;

    if (bravos->inicio == NULL)
    {
        bravos->inicio = bravos->fim = nova;
    }

    else
    {
        bravos->fim->prox = nova;
        bravos->fim = nova;
    }
}

void CadastraGatoMansoLista(tLista *mansos, Gato *gato)
{
    tCelula *nova = malloc(sizeof(tCelula));

    nova->gato = gato;
    nova->prox = NULL;
    nova->identificador = GATO;

    if (mansos->inicio == NULL)
    {
        mansos->inicio = mansos->fim = nova;
    }

    else
    {
        mansos->fim->prox = nova;
        mansos->fim = nova;
    }
}

void CadastraCachorroBravoLista(tLista *bravos, Cachorro *cachorro)
{
    tCelula *nova = malloc(sizeof(tCelula));

    nova->cachorro = cachorro;
    nova->prox = NULL;
    nova->identificador = CACHORRO;

    if (bravos->inicio == NULL)
    {
        bravos->inicio = bravos->fim = nova;
    }

    else
    {
        bravos->fim->prox = nova;
        bravos->fim = nova;
    }
}

void CadastraCachorroMansoLista(tLista *mansos, Cachorro *cachorro)
{
    tCelula *nova = malloc(sizeof(tCelula));

    nova->cachorro = cachorro;
    nova->prox = NULL;
    nova->identificador = CACHORRO;

    if (mansos->inicio == NULL)
    {
        mansos->inicio = mansos->fim = nova;
    }

    else
    {
        mansos->fim->prox = nova;
        mansos->fim = nova;
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

float CalculaReceitaListaBravos(tLista *bravos)
{
    float valor = 0.0;

    tCelula *celula;

    for (celula = bravos->inicio; celula != NULL; celula = celula->prox)
    {
        if (celula->identificador == CACHORRO)
        {
            valor += 45;
        }

        else if (celula->identificador == GATO)
        {
            valor += 35;
        }
    }

    return valor;
}

float CalculaReceitaListaMansos(tLista *mansos)
{
    float valor = 0.0;

    tCelula *celula;

    for (celula = mansos->inicio; celula != NULL; celula = celula->prox)
    {
        if (celula->identificador == CACHORRO)
        {
            valor += 40;
        }

        else if (celula->identificador == GATO)
        {
            valor += 30;
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

void InsereGatoMansoLista(tLista *mansos, Gato *gato)
{
    tCelula *nova = malloc(sizeof(tCelula));

    nova->gato = gato;
    nova->prox = NULL;
    nova->identificador = GATO;

    if (mansos->inicio == NULL)
    {
        mansos->inicio = mansos->fim = nova;
    }

    else
    {
        mansos->fim->prox = nova;
        mansos->fim = nova;
    }
}

void InsereGatoBravoLista(tLista *bravos, Gato *gato)
{
    tCelula *nova = malloc(sizeof(tCelula));

    nova->gato = gato;
    nova->prox = NULL;
    nova->identificador = GATO;

    if (bravos->inicio == NULL)
    {
        bravos->inicio = bravos->fim = nova;
    }

    else
    {
        bravos->fim->prox = nova;
        bravos->fim = nova;
    }
}

void InsereCachorroMansoLista(tLista *mansos, Cachorro *cachorro)
{
    tCelula *nova = malloc(sizeof(tCelula));

    nova->cachorro = cachorro;
    nova->prox = NULL;
    nova->identificador = CACHORRO;

    if (mansos->inicio == NULL)
    {
        mansos->inicio = mansos->fim = nova;
    }

    else
    {
        mansos->fim->prox = nova;
        mansos->fim = nova;
    }
}

void InsereCachorroBravoLista(tLista *bravos, Cachorro *cachorro)
{
    tCelula *nova = malloc(sizeof(tCelula));

    nova->cachorro = cachorro;
    nova->prox = NULL;
    nova->identificador = CACHORRO;

    if (bravos->inicio == NULL)
    {
        bravos->inicio = bravos->fim = nova;
    }

    else
    {
        bravos->fim->prox = nova;
        bravos->fim = nova;
    }
}

Gato *RetiraGatoMansoLista(tLista *mansos, Gato *gato)
{
    Gato *cat;
    tCelula *p = mansos->inicio;
    tCelula *ant = NULL;

    while (p != NULL && strcmp(retornaNomeGato(p->gato), retornaNomeGato(gato)) != 0)
    {
        ant = p;
        p = p->prox;
    }

    // unica celula
    if (p == mansos->inicio && p == mansos->fim)
    {

        mansos->inicio = NULL;
        mansos->fim = NULL;
    }
    // primeira celula
    else if (p == mansos->inicio)
    {
        mansos->inicio = p->prox;
    }
    // ultima celula
    else if (p == mansos->fim)
    {
        mansos->fim = ant;
        mansos->fim->prox = NULL;
    }
    // entre duas celulas
    else
    {
        ant->prox = p->prox;
    }

    cat = p->gato;

    free(p);

    return cat;
}

Gato *RetiraGatoBravoLista(tLista *bravos, Gato *gato)
{
    Gato *cat;
    tCelula *p = bravos->inicio;
    tCelula *ant = NULL;

    while (p != NULL && strcmp(retornaNomeGato(p->gato), retornaNomeGato(gato)) != 0)
    {
        ant = p;
        p = p->prox;
    }

    // unica celula
    if (p == bravos->inicio && p == bravos->fim)
    {

        bravos->inicio = NULL;
        bravos->fim = NULL;
    }
    // primeira celula
    else if (p == bravos->inicio)
    {
        bravos->inicio = p->prox;
    }
    // ultima celula
    else if (p == bravos->fim)
    {
        bravos->fim = ant;
        bravos->fim->prox = NULL;
    }
    // entre duas celulas
    else
    {
        ant->prox = p->prox;
    }

    cat = p->gato;

    free(p);

    return cat;
}

Cachorro *RetiraCachorroMansoLista(tLista *mansos, Cachorro *cachorro)
{
    Cachorro *dog;
    tCelula *p = mansos->inicio;
    tCelula *ant = NULL;

    while (p != NULL && strcmp(retornaNomeCachorro(p->cachorro), retornaNomeCachorro(cachorro)) != 0)
    {
        ant = p;
        p = p->prox;
    }

    // unica celula
    if (p == mansos->inicio && p == mansos->fim)
    {

        mansos->inicio = NULL;
        mansos->fim = NULL;
    }
    // primeira celula
    else if (p == mansos->inicio)
    {
        mansos->inicio = p->prox;
    }
    // ultima celula
    else if (p == mansos->fim)
    {
        mansos->fim = ant;
        mansos->fim->prox = NULL;
    }
    // entre duas celulas
    else
    {
        ant->prox = p->prox;
    }

    dog = p->cachorro;

    free(p);

    return dog;
}

Cachorro *RetiraCachorroBravoLista(tLista *bravos, Cachorro *cachorro)
{
    Cachorro *dog;
    tCelula *p = bravos->inicio;
    tCelula *ant = NULL;

    while (p != NULL && strcmp(retornaNomeCachorro(p->cachorro), retornaNomeCachorro(cachorro)) != 0)
    {
        ant = p;
        p = p->prox;
    }

    // unica celula
    if (p == bravos->inicio && p == bravos->fim)
    {

        bravos->inicio = NULL;
        bravos->fim = NULL;
    }
    // primeira celula
    else if (p == bravos->inicio)
    {
        bravos->inicio = p->prox;
    }
    // ultima celula
    else if (p == bravos->fim)
    {
        bravos->fim = ant;
        bravos->fim->prox = NULL;
    }
    // entre duas celulas
    else
    {
        ant->prox = p->prox;
    }

    dog = p->cachorro;

    free(p);

    return dog;
}