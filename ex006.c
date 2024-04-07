
#include <stdio.h>

int main()
{

    int n, m, x, y, k, d, qnt_minutos= 0;
    int position[2] = {0, 0};
    
    // fazendo o scan das coordenadas
    
    scanf("%d %d %d %d %d", &n, &m, &x, &y, &k);
    
    for(int i = 0; i < k; i++){
        
        //if (((position[0] + 1 == x) || (position[0] - 1 == x) || (position[0] == x)) && (position[1] == y) ||
    //((position[1] + 1 == y) || (position[1] - 1 == y) || (position[1] == y)) && (position[0] == x)) qnt_minutos++;
    
        
        scanf("%d", &d);
        
        switch(d){
            case 1:
            position[1]++;
            break;
            case 2:
            position[1]--;
            break;
            case 3:
            position[0]++;
            break;
            case 4:
            position[0]--;
            break;
        }
        
        if(((position[0] == x)||(position[0] + 1 == x)||(position[0] - 1 == x))&&((position[1] == y)||(position[1] + 1 == y)||(position[1] - 1 == y)))qnt_minutos++;
       
       
    }
    

    printf("%d", qnt_minutos);












    return 0;
}
