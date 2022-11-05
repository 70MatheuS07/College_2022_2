#include "listaLike.h"

int main(void) {
  
    tListaLike* listaLike;
    listaLike = CriaListaLike();
    tLike* like;
    int n = 0;
    int curtida = 3;
    char* nome =  malloc(100*sizeof(char));

    while(1){
        printf("1 - Dar like\n2 - Retirar like\n0 - Encerrar programa\n");
        scanf("%d", &n);
        //sair
        if(n == 0){
            break;
        }
        //Dar like
        else if(n == 1){
          
            printf("Nome da pessoa\n");
            scanf("%s", nome);
          
            printf("0 - like, 1 - deslike\n");
            scanf("%d", &curtida);

          
            like = CriaLike(nome, curtida);
          
            InsereLikeLista(listaLike, like);
          
          
        }
        //retira
        else if(n == 2){
          
            printf("Nome\n");
            scanf("%s", nome);
          
            RetiraDaListaLike(listaLike, nome);
          
        }
        //imprime lista atualizada
        printf("ListaLike Atualizada!\n");
        ImprimeListaLike(listaLike);
    }
  free(nome);
  //libera memoria
  LiberaListaLike(listaLike);
  
  return 0;
}