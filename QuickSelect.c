#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b){
    int aux = *a;
    *a = *b;
    *b = aux;
}

void medianaTres(int *v, int l, int r){
    int m = (r + l) / 2;
    if(v[l] > v[m]) swap(&v[l], &v[m]); 
    if(v[m] > v[r]) swap(&v[m], &v[r]);
    if(v[l] > v[m]) swap(&v[l], &v[m]);
    swap(&v[r], &v[m]);
}

int partition(int *v, int l, int r){
    medianaTres(v, l, r);
    int pivo = v[r];
    int i = l - 1;
    
    for(int j = l; j < r; j++){
        if(v[j] < pivo){
            i++;
            swap(&v[i], &v[j]);
        }
    }
    swap(&v[i+1], &v[r]);
    return i+1;
}

void quickSort(int *v, int l, int r){
    if(l < r){
        int m = partition(v, l, r);
        quickSort(v, l, m-1);
        quickSort(v, m+1, r);
    }
}

void quickSelect(int *v, int l, int r, int k) {
    if (l <= r) { 
        int pivotIndex = partition(v, l, r);

        if (pivotIndex == k)
            return; 
        else if (pivotIndex < k)
            quickSelect(v, pivotIndex + 1, r, k); 
        else
            quickSelect(v, l, pivotIndex - 1, k); 
    }
}

int main() {
    int n, p, x = 0;
    
    scanf("%d %d %d", &n, &p, &x);
    
    int *v = malloc(sizeof(int) * n);
    
    for(int i = 0; i < n; i++){
        scanf("%d", &v[i]);
    }

    int inicio = x * p;
    int fim = inicio + x - 1;
    fim = (fim < n) ? fim : n-1; 
    quickSelect(v, 0, n-1, inicio); 
    quickSelect(v, inicio+1, n-1, fim); 

    quickSort(v, inicio, fim);
    
    for(int i = inicio; (i <= fim); i++){ 
        printf("%d\n", v[i]);
    }
    
    free(v); // Liberar memória alocada
    return 0;
}