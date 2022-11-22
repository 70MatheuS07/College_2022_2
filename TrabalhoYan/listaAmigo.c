#include "listaAmigo.h"

typedef struct Celula tCelula;

struct Celula
{
    tAmigo *amigo;
    tCelula *prox;
};

struct ListaAmigo
{
    tCelula *inicio;
    tCelula *fim;
};

tListaAmigo *CriaListaAmigo()
{
    tListaAmigo *listaAmigo = malloc(sizeof(tListaAmigo));

    listaAmigo->inicio = NULL;
    listaAmigo->fim = NULL;

    return listaAmigo;
}

void InsereAmigoLista(tListaAmigo *listaAmigo, tAmigo *amigo)
{
    tCelula *nova = malloc(sizeof(tCelula));

    nova->amigo = amigo;
    nova->prox = NULL;

    if (listaAmigo->inicio == NULL)
    {
        listaAmigo->inicio = listaAmigo->fim = nova;
    }

    else
    {
        listaAmigo->fim->prox = nova;
        listaAmigo->fim = nova;
    }
}

int NomeNaLista(tListaAmigo *listaAmigo, char* nome){
  
    tCelula *p = listaAmigo->inicio;
    tCelula *ant = NULL;

    while (p != NULL && EhNomeAmigoIgual(p->amigo, nome) != 0)
    {
        ant = p;
        p = p->prox;
    }
  
    if(p == NULL){
        return 0;
    }
  
    return 1;
}

void CriaInsereAmigoNaLista(tListaAmigo *listaAmigo, char* nome){

    if(NomeNaLista(listaAmigo, nome) == 0){
      
        tAmigo* amigo = CriaAmigo(nome);
      
        InsereAmigoLista(listaAmigo, amigo);
      
    }
}

int RetornaNumeroDeAmigos(tListaAmigo *listaAmigo){
    tCelula *celula;
    int n = 0;

    for (celula = listaAmigo->inicio; celula != NULL; celula = celula->prox)
    {
        n++;
    }

    return n;
 
}

void RetiraDaListaAmigo(tListaAmigo *listaAmigo, char *nome)
{

    tCelula *p = listaAmigo->inicio;
    tCelula *ant = NULL;

    while (p != NULL && EhNomeAmigoIgual(p->amigo, nome) != 0)
    {
        ant = p;
        p = p->prox;
    }

    if(p == NULL){
        return;
    }

    // unica celula
    if (p == listaAmigo->inicio && p == listaAmigo->fim)
    {

        listaAmigo->inicio = NULL;
        listaAmigo->fim = NULL;
    }
    // primeira celula
    else if (p == listaAmigo->inicio)
    {
        listaAmigo->inicio = p->prox;
    }
    // ultima celula
    else if (p == listaAmigo->fim)
    {
        listaAmigo->fim = ant;
        listaAmigo->fim->prox = NULL;
    }
    // entre duas celulas
    else
    {
        ant->prox = p->prox;
    }

    LiberaAmigo(p->amigo);

    free(p);
    p = NULL;
}

void LiberaListaAmigo(tListaAmigo *listaAmigo)
{
    tCelula *p = listaAmigo->inicio;
    tCelula *t;

    while (p != NULL)
    {
        t = p->prox;
        LiberaAmigo(p->amigo);

        free(p);
        p = NULL;

        p = t;
    }

    free(listaAmigo);
    listaAmigo = NULL;
}

void ImprimeListaAmigo(tListaAmigo *listaAmigo)
{
    tCelula *celula;

    for (celula = listaAmigo->inicio; celula != NULL; celula = celula->prox)
    {
        ImprimeAmigo(celula->amigo);
    }
}