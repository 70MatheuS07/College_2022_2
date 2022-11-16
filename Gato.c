//
//  gato.c
//  BanhoTosaED
//
//  Created by Patricia Dockhorn Costa on 19/06/22.
//

#include "Gato.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct gato {
    char* nome;
    int agressividade;
};

Gato* inicGato(char* nome, int agressividade){
    Gato* cat = malloc(sizeof(Gato));
    cat->nome = strdup(nome);
    cat->agressividade = agressividade;
    return cat;
}

char* retornaNomeGato(Gato* cat){
    return cat->nome;
}

int retornaNivelAgressividadeGato (Gato* cat){
    return cat->agressividade;
}

void atribuiNivelAgressividadeGato (Gato* cat, int nivel){
    cat->agressividade = nivel;
}

void imprimeGato(Gato* cat){
    printf("\n Nome Gato: %s, Nível Agressividade: %d", cat->nome, cat->agressividade);
}

void liberaGato(Gato* cat){
    free(cat->nome);
    free(cat);
}
