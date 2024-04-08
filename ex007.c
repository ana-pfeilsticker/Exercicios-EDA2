#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int cod_instrucao;
    char comando[16];
} Instruction;

int compare(const void *a, const void *b) {
    return ((Instruction*)a)->cod_instrucao - ((Instruction*)b)->cod_instrucao;
}

int main() {
    int possui = 1;
    int qtd_memoria = 0;
    scanf("%d", &qtd_memoria);
    Instruction instrucoes[qtd_memoria];

    for (int i = 0; i < qtd_memoria; i++) {
        scanf("%d %s", &instrucoes[i].cod_instrucao, instrucoes[i].comando);
    }

    qsort(instrucoes, qtd_memoria, sizeof(Instruction), compare);

    int cod_desejado = 0;
    while (scanf("%d", &cod_desejado) != EOF) {
        possui = 1;
        int left = 0, right = qtd_memoria - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (instrucoes[mid].cod_instrucao == cod_desejado) {
                printf("%s\n", instrucoes[mid].comando);
                possui = 0;
                break;
            } else if (instrucoes[mid].cod_instrucao < cod_desejado) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        if (possui == 1) {
            printf("undefined\n");
        }
    }

    return 0;
}
