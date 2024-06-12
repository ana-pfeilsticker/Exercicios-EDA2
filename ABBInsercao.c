#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int key;
    struct node *left, *right;
} node;

node* inserir(node *r, int x) {
    if (r == NULL) {
        node *novo = (node*) malloc(sizeof(node));
        if (novo == NULL) {
            printf("Erro de alocação de memória\n");
            exit(1);
        }
        novo->key = x;
        novo->left = NULL;
        novo->right = NULL;
        return novo;
    }
    
    if (x < r->key) {
        r->left = inserir(r->left, x);
    } else if (x > r->key) {
        r->right = inserir(r->right, x);
    }
   
    return r;
}