
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct semente {
    long int valor;
    long int cod_semente;
} sem;

void swap(sem *a, sem *b) {
    sem aux = *a;
    *a = *b;
    *b = aux;
}

void intercala(sem *v, int l, int m, int r) {
    sem *w = malloc(sizeof(sem) * (r - l + 1));
    int i = l;
    int j = m + 1;
    int k = 0;

    while (i <= m && j <= r) {
        if (v[i].cod_semente < v[j].cod_semente)
            w[k++] = v[i++];
        else
            w[k++] = v[j++];
    }

    while (i <= m)
        w[k++] = v[i++];

    while (j <= r)
        w[k++] = v[j++];

    k = 0;

    for (int p = l; p <= r; p++) {
        v[p] = w[k++];
    }

    free(w); // Libera a memória alocada para o vetor temporário
}

void mergeSort(sem *v, int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(v, l, m);
        mergeSort(v, m + 1, r);
        intercala(v, l, m, r);
    }
}



void medianaTresValor(sem *v, int l, int r) {
    int m = (r + l) / 2;
    if (v[l].valor > v[m].valor)
        swap(&v[l], &v[m]);
    if (v[m].valor > v[r].valor)
        swap(&v[m], &v[r]);
    if (v[l].valor > v[m].valor)
        swap(&v[l], &v[m]);
    swap(&v[r], &v[m]);
}


int partitionValor(sem *v, int l, int r) {
    medianaTresValor(v, l, r);
    int pivo = v[r].valor;
    int i = l - 1;
    int j = r;

    for (;;) {
        while ((v[++i].valor < pivo) || (v[i].valor == pivo && v[i].cod_semente < v[r].cod_semente))
            ;

        while ((v[--j].valor > pivo) || pivo == v[j].valor && v[r].cod_semente < v[j].cod_semente){
            if(j == l){
                break;
            }
        }
        
        if( i >= j){
            break;
        }
            

        swap(&v[i], &v[j]);
    }

    swap(&v[i], &v[r]);
    return i;
}


void quickSelect(sem *v, int l, int r, int k) {
    if (l <= r) {
        int pivotIndex = partitionValor(v, l, r);

        if (pivotIndex == k)
            return;
        else if (pivotIndex < k)
            quickSelect(v, pivotIndex + 1, r, k);
        else
            quickSelect(v, l, pivotIndex - 1, k);
    }
}

int main() {
    int k = 0;

    scanf("%d", &k);

    sem *v = malloc(sizeof(sem) * pow(10,7));

    int i = 0;

    while (scanf("%ld %ld", &v[i].cod_semente, &v[i].valor) != EOF) {
        i++;
    }

    quickSelect(v, 0, i-1 , k -1);
    mergeSort(v, 0, k -1);

    for (int j = 0; j < k; j++) {
        printf("%ld %ld\n", v[j].cod_semente, v[j].valor);
    }

    free(v);
    return 0;
}