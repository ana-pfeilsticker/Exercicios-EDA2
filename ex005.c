#include <stdio.h>


int main(){
    

    int n, m, p, c = 0;
    scanf("%d %d", &n, &m);
    scanf("%d ", &p);

    int PA[2], PB[2];
    int movimentos[p];
    PA[0] = 1; PA[1] = 1; PB[0] = n; PB[1] = m;
    
    
    for(int i=1; i <= p; i++){
        scanf("%d %d", &movimentos[0], &movimentos[1]);
        switch(movimentos[0]){
            case 1: 
            PA[1]++;
            break;
            case 2:
            PA[1]--;
            break;
            case 3:
            PA[0]++;
            break;
            case 4:
            PA[0]--;
            break;
        }
        
        switch(movimentos[1]){
            case 1: 
            PB[1]++;
            break;
            case 2:
            PB[1]--;
            break;
            case 3:
            PB[0]++;
            break;
            case 4:
            PB[0]--;
            break;
        }
        
        if((PA[0] == PB[0])&&(PA[1] == PB[1])){
            printf("Encontraram-se na posicao (%d,%d) no passo %d\n", PA[0], PA[1], i);
            c++;
            break;
            
        }
        
        if((PA[0] > n)||(PA[0] < 1)||(PA[1] < 1)||(PA[1] > m)){
            printf("PA saiu na posicao (%d,%d) no passo %d\n", PA[0], PA[1], i);
            c++;
            break;
    
        }
        
        else if((PB[0] > n)||(PB[0] < 1)||(PB[1] < 1)||(PB[1] > m)){
            printf("PB saiu na posicao (%d,%d) no passo %d\n", PB[0], PB[1], i);
            c++;
            break;

        }
        
    }
    
    if(c == 0){
        printf("Nao se encontraram\n");
    }
        
                
    return 0;
}