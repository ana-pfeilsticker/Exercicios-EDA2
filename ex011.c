
#include <stdio.h>
#include <stdlib.h>
typedef struct celula {
   int dado;
   struct celula *prox;
} celula;

void insere_inicio (celula *le, int x){
    celula *aux = malloc(sizeof(le));
    aux->dado = x;
    aux->prox = le->prox;
    le->prox = aux;
}

void insere_antes (celula *le, int x, int y){
    celula *aux = le;
    celula *elemento_inserido = malloc(sizeof(le));
    elemento_inserido->dado = x;
    elemento_inserido->prox = NULL;
    
    while(aux->prox != NULL){
        if(aux->prox->dado == y){
            elemento_inserido->prox = aux->prox;
            aux->prox = elemento_inserido;
            return;
        }
        aux = aux->prox;
    }
    
    aux->prox = elemento_inserido;
}