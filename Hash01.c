#include <stdio.h>
#include <stdlib.h>


typedef struct Node{
    int key;
    struct Node *next;
}Node;


typedef struct {
    int size;
    Node **table; //array de nós, cada elemento desse array aponta para o primeiro nó de uma lista encadeada
}HashTable;

int hash(int key, int size) {

    return (key % size);
}

HashTable *createHash(int size){
    HashTable *ht = (HashTable *)malloc(sizeof(HashTable)); //criando uma struct com estrutura de hash que irá conter o seu tamajo e o array de de ponteiros que apontam para o nó que é o inicio de um alista encadeada
    ht->size = size;
    ht->table = (Node **)malloc(sizeof(Node *) * size);    //declarando a table da hash com um malloc da quantidade de elementos vezes uma struct nó, para criar o array com os nós
    
    for (int i=0; i < size; i++){ //declarando todos os nós como NULL
        ht->table[i]  = NULL;
    }
    
    return ht;  //retorna a hash
}

void insertHash(HashTable *ht, int key){   //inserindo na tablea hash
    int index = hash(key, ht->size);       //verificando qual será o indice da lista de nós que o elemento será inserido
    Node *new_node = (Node *)malloc(sizeof(Node));  //criando um novo nó para o elemento 
    new_node->key = key; //declarando o valor, chave do nó como o valor que queremos inserir na hash
    new_node->next = NULL;
    
    if(ht->table[index] == NULL){
        ht->table[index] = new_node;
    } else{
        Node *current = ht->table[index];
        while(current->next !=NULL){
            current = current->next;
        }
        
        current->next = new_node;
    }
    
}



void print_table(HashTable *ht) {
    for (int i = 0; i < ht->size; i++) {
        printf("%d -> ", i);
        Node *current = ht->table[i];
        while (current != NULL) {
            printf("%d -> ", current->key);
            current = current->next;
        }
        printf("\\\n");
    }
}

void freeHash(HashTable *ht){       //função para liberar o espaço de memória da tabela hash
    for(int i = 0; i < ht->size; i++){ //percorrendo o vetor
        Node *current = ht->table[i];
        while(current != NULL){   //percorrendo cada lista encadeada, dando free em todos os seus nós
            Node *temp = current;
            current = current->next;
            free(temp);
        }
    }
    free(ht->table); //liberamos todo o espaço utilizado no malloc para criar a table
    free(ht); //liberamos todo espaço utilizado no malloc para criar a estrutura de hash
}



int main(){
    int qtdcasos = 0;
    scanf("%d", &qtdcasos);
    
    
    while(qtdcasos--){  //para cada caso vamos repetir o processo
        int size, qtdkeys = 0;
        scanf("%d %d",&size, &qtdkeys);
        
        HashTable *ht = createHash(size); //cria a hash com o tamanho solicitado
        
        for(int i = 0 ; i < qtdkeys; i++){
            int key = 0;
            scanf("%d", &key);
            insertHash(ht, key);  //insere os elementos
        }
        
        print_table(ht);  //printa a hash
        
        freeHash(ht);  //libera o espaço da hash
        if(qtdcasos > 0){
            printf("\n");   //se ainda tiver mais casos, ele pula a linha para printar os próximos
        }
    }
    
    return 0;

}