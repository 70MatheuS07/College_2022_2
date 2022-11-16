//
//  cachorro.h
//  BanhoTosaED
//
//  Created by Patricia Dockhorn Costa on 19/06/22.
//

#ifndef cachorro_h
#define cachorro_h

#define MANSO 0
#define BRAVO 1

#include <stdio.h>

/*Tipo que define o animal CACHORRO (tipo opaco)
 *Neste exemplo simples, um cachorro é definido por seu nome e seu nível de agressividade
 * */
typedef struct cachorro Cachorro;

//inicia um CACHORRO, com um nome e um certo nível de agressividade
//A função deve alocar dinamicamente a string nome
Cachorro* inicCachorro(char* nome, int agressividade);

//retorna o nome do cachorro
char* retornaNomeCachorro(Cachorro* dog);

//retorna o nível de agressividade do cachorro
int retornaNivelAgressividadeCachorro (Cachorro* dog);

//atribui ao cachorro o nível de agressividade passado como argumento
void atribuiNivelAgressividadeCachorro (Cachorro* dog, int nivel);

//Imprime as informações do cachorro (nome e nível de agressividade)
void imprimeCachorro(Cachorro* dog);

//Libera a memória alocada para o cachorro
void liberaCachorro(Cachorro* dog);


#endif /* cachorro_h */
