#include <stdio.h>
#include <stdlib.h>


typedef struct no {
   int dado;
   struct no esq,dir;
} no;


typedef struct StackNode {
    no treeNode;
    struct StackNodenext;
}StackNode;


void push(StackNode top, no treeNode){
    StackNodenovoStackNode = (StackNode )malloc(sizeof(StackNode));
    novoStackNode->treeNode = treeNode;
    novoStackNode->next =top;
    top = novoStackNode;
}


no pop(StackNode top){
    if(top ==NULL){
        return NULL;
    }

    StackNodetemp = *top;
    top = (top)->next;
    no noDesempilhado = temp->treeNode;
    free(temp);
    return noDesempilhado;
}


int isEmpty(StackNodetop){
    return top == NULL;
}


void pos_ordem (no raiz){
    if(raiz ==NULL){
        return;
    }

    StackNodestack = NULL;
    no current = raiz;
    nolastVisited = NULL;



     while (!isEmpty(stack) || current != NULL) {

        while(current!=NULL){
            push(&stack, current);
            current = current->esq;
        }

        no *topNode = stack->treeNode;

        if(topNode->dir !=NULL && topNode->dir != lastVisited){
            current = topNode->dir;
        } else {
            printf("%d", topNode->dado);
            pop(&stack);
            lastVisited = topNode;
        }



    }

    }