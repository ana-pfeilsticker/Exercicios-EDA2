
#include <stdio.h>
#include <stdlib.h>
typedef struct celula {
   int dado;
   struct celula *prox;
} celula;

int remove_depois (celula *p){
    if(p != NULL && p->prox != NULL){
        celula *aux = p->prox;
        int dado_removido = p->prox->dado;
        p->prox = aux->prox;
        free(aux);
        return dado_removido;
    }
}

void remove_elemento (celula *le, int x){
    
    celula *aux = le;
    celula *excluida;
    while(aux->prox != NULL){
        if(aux->prox->dado == x){
            excluida = aux->prox;
            aux->prox = excluida->prox;
            free(excluida);
            return;
    
        }
        aux = aux->prox;
    }
    
}

void remove_todos_elementos (celula *le, int x){
        celula *aux = le;
    celula *excluida;
    while(aux->prox != NULL){
        if(aux->prox->dado == x){
            excluida = aux->prox;
            aux->prox = excluida->prox;
            free(excluida);
    
        }else{
        aux = aux->prox;
    }
}}