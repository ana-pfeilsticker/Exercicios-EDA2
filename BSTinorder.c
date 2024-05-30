#include <stdio.h>
#include <stdlib.h>


typedef struct no {
   int dado;
   struct no *esq, *dir;
} no;


typedef struct StackNode {
    no *treeNode;
    struct StackNode *next;
}StackNode;


void push(StackNode **top, no *treeNode){
    StackNode *novoStackNode = (StackNode *)malloc(sizeof(StackNode));
    novoStackNode->treeNode = treeNode;
    novoStackNode->next = *top;
    *top = novoStackNode;
}


no* pop(StackNode **top){
    if(*top ==NULL){
        return NULL;
    }
    
    StackNode *temp = *top;
    *top = (*top)->next;
    no *noDesempilhado = temp->treeNode;
    free(temp);
    return noDesempilhado;
}


int isEmpty(StackNode *top){
    return top == NULL;
}


void em_ordem (no *raiz){
    if(raiz ==NULL){
        return;
    }
    
    StackNode *stack = NULL;
    no *current = raiz;
    
    while(!isEmpty(stack) || current !=NULL){
        while(current != NULL){
            push(&stack, current);
            current = current->esq;
        }
        
        current = pop(&stack);
        printf("%d ", current->dado);
        
        
        current = current->dir;
    }
    
    }
    
    
    