#include <stdio.h>
#include <stdlib.h>

typedef struct node {
   int key;
   struct node *l, *r;
} node;


node *maximo (node *head){
    
    node* aux = head;
    
    while(aux->r != NULL){
        aux = aux->r;
    }
    
    return aux;    
}