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
        return -1; // Altura de uma árvore vazia é -1
    } else {
        // Calcula a altura das subárvores esquerda e direita
        int altura_esq = altura(r->esq);
        int altura_dir = altura(r->dir);
        
        // A altura da árvore é o máximo entre as alturas das subárvores mais 1
        if (altura_esq > altura_dir) {
            return altura_esq + 1;
        } else {
            return altura_dir + 1;
        }
    }
}
