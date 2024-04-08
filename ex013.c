
#include <stdio.h>

typedef struct celula {
   int dado;
   struct celula *prox;
} celula;

celula *busca (celula *le, int x){
    celula *aux = le->prox;
    while(aux != NULL){
        if(aux->dado == x){
            return aux;
        }
        aux = aux->prox;
    }
    return NULL;
}

celula *busca_rec (celula *le, int x){

    if(le == NULL){
        return NULL;
    } else{
        if(le->dado == x){
            return le;
        }
    }
    
    return busca_rec(le->prox, x);
}

