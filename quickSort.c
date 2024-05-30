#include <stdio.h>
#include <stdlib.h>

// Primeiro vamos fazer a função de troca
void swap(int *v, int a, int b) {
    int aux = v[a];
    v[a] = v[b];
    v[b] = aux;
}

void medianaTres(int *v, int l, int r) {
    int m = (l + r) / 2;
    if (v[l] > v[r]) swap(v, l, r);
    if (v[m] > v[r]) swap(v, m, r);
    if (v[l] > v[m]) swap(v, m, l);
    swap(v, m, r);
}

int quick(int *v, int l, int r) {
    medianaTres(v, l, r);

    int pivo = v[r];
    int j, k;
    for (k = l, j = l; k < r; k++) {
        if (v[k] <= pivo) {
            swap(v, k, j);
            j++;
        }
    }
    swap(v, j, r);
    return j;
}

void QuickSort(int *v, int l, int r) {
    if (l < r) {
        int j = quick(v, l, r);
        QuickSort(v, l, j-1);
        QuickSort(v, j + 1, r);
    }
}

int main() {
    int n;

    
    if (scanf("%d", &n) != 1) {

        return 1;
    }

    int *v = (int *)malloc(n * sizeof(int));
    if (v == NULL) {

        return 1;
    }


    for (int i = 0; i < n; i++) {
        if (scanf("%d", &v[i]) != 1) {

            free(v);
            return 1;
        }
    }

    QuickSort(v, 0, n - 1);


    for (int j = 0; j < n; j++) {
        j == n-1 ? printf("%d", v[j]) : printf("%d ", v[j]);
    }

    printf("\n");

    free(v);

    return 0;
}