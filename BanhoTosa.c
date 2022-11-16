#include "BanhoTosa.h"
#include <string.h>

struct banhotosa
{
    char *nome;
    tLista *animais;
};

BanhoTosa *inicBanhoTosa(char *nome)
{
    char *nomeLoja;

    nomeLoja = strdup(nome);

    BanhoTosa *loja = malloc(sizeof(BanhoTosa));

    loja->nome = nomeLoja;

    loja->animais = CriaLista();

    return loja;
}

void cadastraCachorro(BanhoTosa *loja, Cachorro *dog)
{
    CadastraCachorroLista(loja->animais, dog);
}

void cadastraGato(BanhoTosa *loja, Gato *cat)
{
    CadastraGatoLista(loja->animais, cat);
}

void imprimeBanhoTosa(BanhoTosa *loja)
{
    printf("Loja: %s\n", loja->nome);
    ImprimeLista(loja->animais);
}

float calculaReceita(BanhoTosa *loja)
{
    float valor=0.0;

    valor = CalculaReceitaLista(loja->animais);

    return valor;
}

void liberaBanhoTosa(BanhoTosa *loja)
{
    LiberaLista(loja->animais);

    free(loja->nome);

    free(loja);
}

void atualizaSituacaoGato(BanhoTosa* loja, Gato* cat)
{
    BuscaModificaAnimalLista(loja->animais, cat);
}