
#include <stdio.h>
#include <string.h>

int main()
{

    char s[10], r[10];
    
    scanf("%s %s", s, r);
    
    char regras[10][2][10] = {
        {"tesoura", "papel"},
        {"papel", "pedra"},
        {"pedra", "lagarto"},
        {"lagarto", "Spock"},
        {"Spock", "tesoura"},
        {"tesoura", "lagarto"},
        {"lagarto", "papel"},
        {"papel", "Spock"},
        {"Spock", "pedra"},
        {"pedra", "tesoura"}
    };
    
    if(strcmp(s, r) == 0){
            printf("De novo!\n");
            return 0;
        }

    
    for(int i = 0; i < 10; i++){
        if((strcmp(s, regras[i][0]) == 0)&&(strcmp(r, regras[i][1]) == 0)){
            printf("Bazinga!\n");
            return 0;
        }
    }
    
    printf("Raj trapaceou!\n");
    
    return 0;
}
