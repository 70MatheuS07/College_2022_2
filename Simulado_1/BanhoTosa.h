//
//  BanhoTosa.h
//  BanhoTosaED
//
//  Created by Patricia Dockhorn Costa on 19/06/22.
//

#ifndef BanhoTosa_h
#define BanhoTosa_h

#include <stdio.h>
#include "Gato.h"
#include "Cachorro.h"
#include "lista.h"

/*Tipo que define a loja de banho e tosa (tipo opaco)
 *Cada loja deve ter os seguintes atributos:
 * * Nome da loja
 * * Uma lista de animais (gatos e cachorros) agressivos
 * * Uma lista de animais (gatos e cachorros) mansos
 * */
typedef struct banhotosa BanhoTosa;


/* Cria uma loja de banho e tosa, ainda vazia, com duas listas de animais vazias
* inputs: nome da loja (char*). Esta função deve alocar dinamicamente o nome da loja.
* output: loja alocada e vazia, com listas de animais ainda vazias
* pre-condicao: nao tem
* pos-condicao: loja alocada e vazia, com listas de animais criadas e vazias  */
BanhoTosa* inicBanhoTosa(char* nome);

/* Insere o cachorro em uma das listas de animais, dependendo do seu nível de agressividade
* inputs: referência para a loja e a referência para o animal
* output: nenhum
* pre-condicao: loja alocada e animal alocado
* pos-condicao: loja contém o animal e uma de suas listas, dependendo do nível de agressividade do animal  */
void cadastraCachorro(BanhoTosa* loja, Cachorro* dog);

/* Insere o cachorro em uma das listas de animais, dependendo do seu nível de agressividade
* inputs: referência para a loja e a referência para o animal
* output: nenhum
* pre-condicao: loja alocada e animal alocado
* pos-condicao: loja contém o animal e uma de suas listas, dependendo do nível de agressividade do animal  */
void cadastraGato(BanhoTosa* loja, Gato* cat);


/* Essa função atualiza a situação de um gato na loja. Caso ele esteja na lista errada, ele é devidamente MOVIDO para a lista correta.
* inputs: referência para a loja e a referência para o animal
* output: nenhum
* pre-condicao: loja alocada e animal alocado
* pos-condicao: animal deve estar na lista correta, de acordo com seu nível de agressividade */
void atualizaSituacaoGato(BanhoTosa* loja, Gato* cat);

/* Essa função atualiza a situação de um cachorro na loja. Caso ele esteja na lista errada, ele é devidamente MOVIDO para a lista correta.
* inputs: referência para a loja e a referência para o animal
* output: nenhum
* pre-condicao: loja alocada e animal alocado
* pos-condicao: animal deve estar na lista correta, de acordo com seu nível de agressividade */
void atualizaSituacaoCachorro(BanhoTosa* loja, Cachorro* dog);


/* Imprime os dados da Loja (nome, e conteúdo das listas)
* inputs: referencia para a loja
* output: nenhum
* pre-condicao: loja alocada
* pos-condicao: nenhuma alteração feita nos conteúdos das estruturas de dados */
void imprimeBanhoTosa(BanhoTosa* loja);


/* Calcula o valor que a loja vai receber caso todos os animais tomem banho.
 Valor Gato: 30 reais, Valor Cachorro: 40 reais. Caso o animal seja agressivo, é cobrado uma taxa extra de 5 reais.
* inputs: referencia para a loja
* output: valor da receita
* pre-condicao: loja alocada
* pos-condicao: nenhuma alteração feita nos conteúdos das estruturas de dados */
float calculaReceita(BanhoTosa* loja);


/* Libera toda a memória alocada
* inputs: referencia para a loja
* output: não tem
* pre-condicao: loja alocada
* pos-condicao: Toda a memória liberada, a não ser gatos e cachorros, que são responsabilidade do cliente. */
void liberaBanhoTosa(BanhoTosa* loja);

#endif /* BanhoTosa_h */
