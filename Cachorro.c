//
//  cachorro.c
//  BanhoTosaED
//
//  Created by Patricia Dockhorn Costa on 19/06/22.
//

#include "Cachorro.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct cachorro {
    char* nome;
    int agressividade;
};

Cachorro* inicCachorro(char* nome, int agressividade){
    Cachorro* dog = malloc(sizeof(Cachorro));
    dog->nome = strdup(nome);
    dog->agressividade = agressividade;
    return dog;
}

char* retornaNomeCachorro(Cachorro* dog){
    return dog->nome;
}

int retornaNivelAgressividadeCachorro (Cachorro* dog){
    return dog->agressividade;
}

void atribuiNivelAgressividadeCachorro (Cachorro* dog, int nivel){
    dog->agressividade = nivel;
}

void imprimeCachorro(Cachorro* dog){
    printf("\n Nome Cachorro: %s, Nível Agressividade: %d", dog->nome, dog->agressividade);
}

void liberaCachorro(Cachorro* dog){
    free(dog->nome);
    free(dog);
}
