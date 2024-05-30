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


void pre_ordem (no *raiz){
    if(raiz ==NULL){
        return;
    }
    
    StackNode *stack = NULL;
    push(&stack, raiz);
    
    
    while(!isEmpty(stack)){
        no *current = pop(&stack);
        printf("%d", current->dado);
        
        if(current->dir != NULL){
            push(&stack, current->dir);
        }
        
        if(current->esq != NULL){
            push(&stack, current->esq);
        }
    }
    
    
}
