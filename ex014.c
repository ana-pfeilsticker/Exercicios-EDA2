
#include <stdio.h>

typedef struct celula {
   int dado;
   struct celula *prox;
} celula;

void mescla_listas (celula *l1, celula *l2, celula *l3){
    for(l1 = l1->prox, l2 = l2->prox; l1 != NULL && l2 != NULL; l3 = l3->prox){
        if(l1->dado < l2->dado){
            l3->prox = l1;
            l1 = l1->prox;
        } else{
            l3->prox = l2;
            l2 = l2->prox;
        }
    }
    
    while(l1 == NULL && l2 != NULL){
        l3->prox = l2;
        l2 = l2->prox;
        l3 = l3->prox;
    }
    
    while(l1 != NULL && l2 == NULL){
        l3->prox = l1;
        l1 = l1->prox;
        l3 = l3->prox;
    }
    
    
}

