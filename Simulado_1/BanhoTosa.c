#include "BanhoTosa.h"
#include <string.h>

struct banhotosa
{
    char *nome;
    tLista *mansos;
    tLista *bravos;
};

BanhoTosa *inicBanhoTosa(char *nome)
{
    char *nomeLoja;

    nomeLoja = strdup(nome);

    BanhoTosa *loja = malloc(sizeof(BanhoTosa));

    loja->nome = nomeLoja;

    loja->mansos = CriaLista();

    loja->bravos = CriaLista();

    return loja;
}

void cadastraCachorro(BanhoTosa *loja, Cachorro *dog)
{
    if (retornaNivelAgressividadeCachorro(dog) == BRAVO)
    {
        CadastraCachorroBravoLista(loja->bravos, dog);
    }

    else
    {
        CadastraCachorroMansoLista(loja->mansos, dog);
    }
}

void cadastraGato(BanhoTosa *loja, Gato *cat)
{
    if (retornaNivelAgressividadeGato(cat) == BRAVO)
    {
        CadastraGatoBravoLista(loja->bravos, cat);
    }

    else
    {
        CadastraGatoMansoLista(loja->mansos, cat);
    }
}

void imprimeBanhoTosa(BanhoTosa *loja)
{
    printf("\nLoja: %s\n", loja->nome);
    ImprimeLista(loja->mansos);
    ImprimeLista(loja->bravos);
}

float calculaReceita(BanhoTosa *loja)
{
    float valor = 0.0;

    valor += CalculaReceitaListaBravos(loja->bravos);
    valor += CalculaReceitaListaMansos(loja->mansos);

    return valor;
}

void liberaBanhoTosa(BanhoTosa *loja)
{
    LiberaLista(loja->bravos);

    LiberaLista(loja->mansos);

    free(loja->nome);

    free(loja);
}

void atualizaSituacaoGato(BanhoTosa *loja, Gato *cat)
{
    Gato *gato;

    if (retornaNivelAgressividadeGato(cat) == BRAVO)
    {
        gato = RetiraGatoMansoLista(loja->mansos, cat);

        InsereGatoBravoLista(loja->bravos, gato);
    }

    else
    {
        gato = RetiraGatoBravoLista(loja->bravos, cat);

        InsereGatoMansoLista(loja->mansos, gato);
    }
}

void atualizaSituacaoCachorro(BanhoTosa *loja, Cachorro *dog)
{
    Cachorro *cachorro;

    if (retornaNivelAgressividadeCachorro(dog) == BRAVO)
    {
        cachorro = RetiraCachorroMansoLista(loja->mansos, dog);

        InsereCachorroBravoLista(loja->bravos, cachorro);
    }

    else
    {
        cachorro = RetiraCachorroBravoLista(loja->bravos, dog);

        InsereCachorroMansoLista(loja->mansos, cachorro);
    }
}