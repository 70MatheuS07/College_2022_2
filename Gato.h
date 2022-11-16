//
//  gato.h
//  BanhoTosaED
//
//  Created by Patricia Dockhorn Costa on 19/06/22.
//

#ifndef gato_h
#define gato_h

#define MANSO 0
#define BRAVO 1

#include <stdio.h>

/*Tipo que define o animal GATO (tipo opaco)
 *Neste exemplo simples, um gato é definido por seu nome e seu nível de agressividade
 * */
typedef struct gato Gato;

//inicia um GATO, com um nome e um certo nível de agressividade
//A função deve alocar dinamicamente a string nome
Gato* inicGato(char* nome, int agressividade);

//retorna o nome do gato
char* retornaNomeGato(Gato* cat);

//retorna no nível de agressividade do gato
int retornaNivelAgressividadeGato (Gato* cat);

//atribui ao gato o nível de agressividade passado como argumento
void atribuiNivelAgressividadeGato (Gato* cat, int nivel);

//Imprime as informações do gato (nome e nível de agressividade)
void imprimeGato(Gato* cat);

//Libera a memória alocada para o gato
void liberaGato(Gato* cat);


#endif /* gato_h */
