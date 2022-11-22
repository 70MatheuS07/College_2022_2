#include "listaHobby.h"

typedef struct Celula tCelula;

struct Celula
{
    tHobby *hobby;
    tCelula *prox;
};

struct ListaHobby
{
    tCelula *inicio;
    tCelula *fim;
};

tListaHobby *CriaListaHobby()
{
    tListaHobby *hobby = malloc(sizeof(tListaHobby));

    hobby->inicio = NULL;
    hobby->fim = NULL;

    return hobby;
}

tListaHobby *ColetaHobbyLista(FILE *arquivo)
{
    int i = 0;
    char caracter;

    tListaHobby *hobbies = CriaListaHobby();

    char *string;
    int tam;

    while (1)
    {
        string = ColetaHobbyArquivo(arquivo);

        tam = strlen(string);

        caracter = string[tam - 1];
        string[tam - 1] = '\0';

        InsereHobbyLista(hobbies, string);
        string = NULL;

        if (feof(arquivo) || caracter == '\n')
        {
            break;
        }
    }

    return hobbies;
}

void InsereHobbyLista(tListaHobby *hobbies, char *hobby)
{
    tCelula *nova = malloc(sizeof(tCelula));

    tHobby *hobbyCriado = CriaHobby(hobby);

    nova->hobby = hobbyCriado;
    nova->prox = NULL;

    if (hobbies->inicio == NULL)
    {
        hobbies->inicio = hobbies->fim = nova;
    }

    else
    {
        hobbies->fim->prox = nova;
        hobbies->fim = nova;
    }
}

void ImprimeListaHobby(tListaHobby *hobbies, FILE *arquivo)
{
    fprintf(arquivo, "HOBBIES\n");
    
    for (tCelula *aux = hobbies->inicio; aux != NULL; aux = aux->prox)
    {
        fprintf(arquivo, "%s\n", RetornaNomeHobby(aux->hobby));
    }

    fprintf(arquivo, "\n");
}

void LiberaListaHobby(tListaHobby *hobbies)
{
    tCelula *aux, *prox;

    aux = hobbies->inicio;

    while (aux != NULL)
    {
        prox = aux->prox;

        LiberaHobby(aux->hobby);

        free(aux);
        aux = NULL;

        aux = prox;
    }

    free(hobbies);
    hobbies = NULL;
}

int ConfereListaHobbyPackage(tListaHobby *hobby)
{
    tCelula *aux = hobby->inicio;

    if (RetornaCharHobby(aux->hobby) == '.')
    {
        return 0;
    }

    return 1;
}

void ImprimeHobbiesEdMatch(tListaHobby *hobby, FILE *arquivo)
{
    char *nome;

    for (tCelula *aux = hobby->inicio; aux != NULL; aux = aux->prox)
    {
        nome = RetornaNomeHobby(aux->hobby);

        fprintf(arquivo, "~ %s\n", nome);
    }
}

void LiberaListaHobbyEdMatch(tListaHobby *hobbies)
{
    tCelula *aux, *prox;

    aux = hobbies->inicio;

    while (aux != NULL)
    {
        prox = aux->prox;

        LiberaHobby(aux->hobby);

        free(aux);
        aux = NULL;

        aux = prox;
    }
}

void CopiaHobbiesPackageParaHobbies(tListaHobby *hobbies, tListaHobby *copia)
{
    for (tCelula *aux = copia->inicio; aux != NULL; aux = aux->prox)
    {
        InsereHobbyLista(hobbies, RetornaNomeHobbyParaCopiaEdMatch(aux->hobby));
    }
}

char RetornaCharListaHobby(tListaHobby *hobby)
{
    char caracter;

    tCelula *aux = hobby->inicio;

    caracter = RetornaCharHobby(aux->hobby);

    return caracter;
}