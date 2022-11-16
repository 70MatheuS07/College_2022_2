//
//  Este é o testador3.c, testa TODAS as funcionalidades
//  Pode valer até 10 pontos.
//
//
//  Created by Patricia Dockhorn Costa on 19/06/22.
//


#include <stdio.h>
#include "BanhoTosa.h"

int main(int argc, const char * argv[]) {

    //cadastra uns cachorrinhos e gatinhos
    //nome e nível de agressividade
    
    Cachorro* iris = inicCachorro("Iris", BRAVO);
    Cachorro* bob = inicCachorro("Bob", MANSO);
    Cachorro* baby = inicCachorro("Baby", MANSO);

    Gato* branca = inicGato("Branca", BRAVO);
    Gato* ronaldo = inicGato("RonaldoCesar", MANSO);
    

    //cria uma instância do banho tosa
    BanhoTosa* loja = inicBanhoTosa("PetShow");
        
    //cadastra os cachorrinhos e gatinhos
    cadastraGato(loja, branca);
    cadastraGato(loja, ronaldo);
    
    cadastraCachorro(loja, iris);
    cadastraCachorro(loja, bob);
    cadastraCachorro(loja, baby);
    
    //imprime tudo
    imprimeBanhoTosa(loja);
    
    //muda nível de agressividade (por exemplo, bob ficou agressivo)
    atribuiNivelAgressividadeCachorro(bob, BRAVO);
    
    //precisa atualizar a situação do Bob na loja
    atualizaSituacaoCachorro(loja, bob);
    
    //mesma coisa com a branca
    atribuiNivelAgressividadeGato(branca, MANSO);
    atualizaSituacaoGato(loja, branca);

    //Imprime tudo agora, com a nova situação da loja
    imprimeBanhoTosa(loja);
    
    
    //calcula valor a receber
    float valor = calculaReceita(loja);
    printf("\nValor a Receber %.2f", valor);
    
    //libera tudo
    liberaBanhoTosa(loja);
    
    liberaGato(branca);
    liberaGato(ronaldo);
    
    liberaCachorro(iris);
    liberaCachorro(bob);
    liberaCachorro(baby);

    return 0;
}
