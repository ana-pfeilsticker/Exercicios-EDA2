#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura do nó
typedef struct no {
    int chave;
    struct no *esq, *dir;
} no;

// Função que retorna a altura da árvore binária de busca
int altura(no *r) {
    if (r == NULL) {
        return 0; // Altura de uma árvore vazia é -1
    } else {
        // Calcula a altura das subárvores esquerda e direita
        int altura_esq = altura(r->esq);
        int altura_dir = altura(r->dir);
        
        return (altura_esq > altura_dir ? altura_esq : altura_dir) + 1;
    }
}
