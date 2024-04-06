#include <stdio.h>
#include <string.h>


int main(){
    
    int controle_entrada = 0;
  
    int f, l = 0; 
    scanf("%d %d", &f, &l);
    
    getchar();

    char matriz_lugares_ocupados[500][4]; 
    
    
    while(scanf("%s", matriz_lugares_ocupados[controle_entrada]) != EOF){
    //while(controle_entrada < 6){
        //scanf("%s", matriz_lugares_ocupados[controle_entrada]);
        matriz_lugares_ocupados[controle_entrada][strlen(matriz_lugares_ocupados[controle_entrada])+1] = '\0';
        controle_entrada++;
    }
    for(int i = 1; i <= l; i++){  
        i == 1?printf("  %02d", i) : printf(" %02d", i);
    }
    
    printf("\n");
    
    int lugar_fechado = 0;
    char lugar_marcado[4];
    for(int i = f-1; i >= 0; i--){ 
  
        for(int j = 0; j <= l; j++){ 
            sprintf(lugar_marcado, "%c%d", i+65, j);
            lugar_marcado[strlen(lugar_marcado)+1] = '\0';
            if(j==0){
                printf("%c", 'A'+ i);
            }
            
            else{
                lugar_fechado = 0;
                for(int k = 0; k < controle_entrada; k++) {
                    if(strcmp(matriz_lugares_ocupados[k], lugar_marcado) == 0) {
                        lugar_fechado = 1; 
                        break;
                    }
                }
                
                lugar_fechado==1?printf(" XX") : printf(" --");
            }

        }
        printf("\n");
    }
    
    return 0;
}