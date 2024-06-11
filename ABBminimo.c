#include <stdio.h>
#include <stdlib.h>

typedef struct node {
   int key;
   struct node *l, *r;
} node;


node *minimo (node *head){
    
    node* aux = head;
    
    while(aux->l != NULL){
        aux = aux->l;
    }
  
    return aux;    
}