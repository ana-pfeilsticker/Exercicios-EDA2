#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *incrementa(char *str, int esquerda, int direita) {
  char *copia = malloc(10000 * sizeof(char));
  bool houveOverflow = false;
  strncpy(copia, str, direita + 1);

  for (int i = direita; i >= esquerda; i--) {
    if (str[i] == '9') {
      if (i == esquerda) {
        copia[i] = '0';
        char *resultado = malloc((direita + 3) * sizeof(char));
        resultado[0] = '1';

        for (int j = 0; j <= direita; j++) {
          resultado[j + 1] = copia[j];
          if (j == direita) resultado[j + 2] = '\0';
        }

        return resultado;
      }
      houveOverflow = true;
      copia[i] = '0';
      continue;
    }
    copia[i] = str[i] + 1;
    break;
  }
  return copia;
}

int main() {
  int tamanho;
  scanf("%d", &tamanho);

  char entrada[10000];

  for (int i = 0; i < tamanho; i++) {
    char caractere;
    scanf(" %c", &caractere);
    entrada[i] = caractere;
  }

  entrada[tamanho] = '\0';

  for (int i = 0; i <= tamanho / 2; i++) {
    bool palindromo = true;
    char substring[10000];
    strncpy(substring, entrada, i + 1);
    char *resultado = incrementa(entrada, 0, i);
    int tamanhoSub = strlen(substring);

    for (int j = i + 1; j < tamanho; j += tamanhoSub) {
      tamanhoSub = strlen(resultado);
      char outraSubstring[10000];
      strncpy(outraSubstring, entrada + j, tamanhoSub);
      outraSubstring[tamanhoSub] = '\0';

      if (strcmp(resultado, outraSubstring)) {
        palindromo = false;
        break;
      } else {
        resultado = incrementa(outraSubstring, 0, tamanhoSub - 1);
      }
    }

    if (palindromo) {
      printf("%s\n", substring);
      return 0;
    }
  }

  printf("%s\n", entrada);

  return 0;
}

    
    
    
    
    
    
    
    
