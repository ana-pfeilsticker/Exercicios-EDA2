#include <stdlib.h>
#include <stdio.h>


typedef struct{
    float nota;
    int m;
    int n;
} Membro;


void swapMembro(Membro *v, int a, int b) {
    Membro aux = v[a];
    v[a] = v[b];
    v[b] = aux;
}

void medianaTres(Membro *v, int l, int r) {
    int m = (l + r) / 2;
    if (v[l].nota > v[r].nota) swapMembro(v, l, r);
    if (v[m].nota > v[r].nota) swapMembro(v, m, r);
    if (v[l].nota > v[m].nota) swapMembro(v, m, l);
    swapMembro(v, m, r);
}

int quick(Membro *v, int l, int r) {
    medianaTres(v, l, r);

    float pivo = v[r].nota;
    int j = l; 
    for (int i = l; i < r; i++) {
        if (v[i].nota > pivo || (v[i].nota == pivo && v[i].m < v[r].m) ||
            (v[i].nota == pivo && v[i].m == v[r].m && v[i].n < v[r].n)) {
            swapMembro(v, i, j);
            j++;
        }
    }
    swapMembro(v, j, r);
    return j;
}

void QuickSort(Membro *v, int l, int r) {
    if (l < r) {
        int j = quick(v, l, r);
        QuickSort(v, l, j-1);
        QuickSort(v, j + 1, r);
    }
}


int main() {
    int t;
    scanf("%d", &t);

    while (t--) {
        int m, n;
        scanf("%d %d", &m, &n);

        Membro *v = (Membro *)malloc(m * n * sizeof(Membro));

        for (int i = 0; i < m * n; i++) {
            scanf("%f", &v[i].nota);
            v[i].m = i / n + 1;
            v[i].n = i % n + 1;
        }

        QuickSort(v, 0, m * n - 1);

        for (int i = 0; i < m * n ; i++) {
            i != (m*n)-1? printf("%d,%d ", v[i].m, v[i].n) : printf("%d,%d", v[i].m, v[i].n);
        }
        printf("\n");

        free(v);
    }

    return 0;
}