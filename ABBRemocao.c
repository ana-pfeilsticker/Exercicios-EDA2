#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura do nó
typedef struct no {
    int chave;
    struct no *esq, *dir;
} no;

// Função auxiliar para encontrar o maior valor na subárvore esquerda
no* encontra_antecessor(no* r) {
    no* atual = r->esq;
    while (atual->dir != NULL) {
        atual = atual->dir;
    }
    return atual;
}

// Função que remove o valor x da árvore binária de busca
no* remover(no* r, int x) {
    if (r == NULL) {
        return NULL; // A chave não está na árvore
    }

    if (x < r->chave) {
        r->esq = remover(r->esq, x);
    } else if (x > r->chave) {
        r->dir = remover(r->dir, x);
    } else {
        // Nó encontrado
        if (r->esq == NULL) {
            no* temp = r->dir;
            free(r);
            return temp;
        } else if (r->dir == NULL) {
            no* temp = r->esq;
            free(r);
            return temp;
        }

        // Nó com dois filhos: obter o antecessor (maior na subárvore esquerda)
        no* temp = encontra_antecessor(r);
        r->chave = temp->chave;
        r->esq = remover(r->esq, temp->chave);
    }
    return r;
}

// Função auxiliar para criar um novo nó
no* novo_no(int chave) {
    no *n = (no*) malloc(sizeof(no));
    n->chave = chave;
    n->esq = NULL;
    n->dir = NULL;
    return n;
}

// Função para inserir um valor na árvore binária de busca (apenas para testes)
no* inserir(no* r, int chave) {
    if (r == NULL) {
        return novo_no(chave);
    }
    if (chave < r->chave) {
        r->esq = inserir(r->esq, chave);
    } else if (chave > r->chave) {
        r->dir = inserir(r->dir, chave);
    }
    return r;
}

// Função para imprimir a árvore (apenas para testes)
void em_ordem(no* r) {
    if (r != NULL) {
        em_ordem(r->esq);
        printf("%d ", r->chave);
        em_ordem(r->dir);
    }
}


