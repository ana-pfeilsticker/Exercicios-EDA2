#include <stdio.h>
#include <stdlib.h>

typedef struct Grafo {
    int n;
    int **adj; //matriz de adjacencia
} g;

g* criagrafo(int n) {
    g *novoGrafo = (g *)malloc(sizeof(g));
    if (novoGrafo == NULL) {
        return NULL;
    }

    novoGrafo->n = n;
    novoGrafo->adj = (int **)malloc(n * sizeof(int *));
    if (novoGrafo->adj == NULL) {
        free(novoGrafo);
        return NULL;
    }

    for (int i = 0; i < n; i++) {
        novoGrafo->adj[i] = (int *)calloc(n, sizeof(int));
        if (novoGrafo->adj[i] == NULL) {
            for (int j = 0; j < i; j++) {
                free(novoGrafo->adj[j]);
            }
            free(novoGrafo->adj);
            free(novoGrafo);
            return NULL;
        }
    }

    return novoGrafo;
}

void liberarGrafo(g *grafo) {
    for (int i = 0; i < grafo->n; i++) {
        free(grafo->adj[i]);
    }
    free(grafo->adj);
    free(grafo);
}

int main() {
    
    int n, m, j, vizinho, contador, juliano, magno;
    
    scanf("%d %d %d", &n, &j, &m);
    g *grafo = criagrafo(n);
    
    for(int i = 0; i < n; i++){
        contador = 0;
        scanf("%d", &contador);
        while(contador--){
    
            scanf("%d", &vizinho);
            grafo->adj[i][vizinho] = 1;
            grafo->adj[vizinho][i] = 1;
        }
    }
    

    int *julianoEsteveAqui = calloc(n, sizeof(int));
    

    while(j--){
        scanf("%d", &juliano);

        julianoEsteveAqui[juliano] = 1;
        
 
        for(int i = 0; i < n; i++){
            if(grafo->adj[juliano][i]) julianoEsteveAqui[i] = 1;
        }
    }

    
    while(m--){
        scanf("%d", &magno);
        if(julianoEsteveAqui[magno]) printf("Eu vou estar la\n");
        else printf("Nao vou estar la\n");
    }
    

    liberarGrafo(grafo);

    return 0;
}