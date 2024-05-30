#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

typedef struct Node{
    long long key;
    long long qtd;
    struct Node *next;
}Node;


typedef struct {
    int size;
    Node **table; //array de nós, cada elemento desse array aponta para o primeiro nó de uma lista encadeada
}HashTable;

int hash(long long key, int size) {
    if (key < 0) {  //caso a chave seja menor que zero, transformamos em positivo e calculamos a posição 
        key = -key;
    }
    return key % size; //retorna a posição do array onde terá esse nó da lista
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



Node * findNode(HashTable *ht, long long key){ //aqui passaremos uma hash, e vamos encontrar o nó, se ele existir retornamos ele, se ele não resistir retornamos NULL
    int index = hash(key, ht->size); //posição de onde o nó deve estar no vetor
    Node *current = ht->table[index]; //definindo o nó cabeça na posição do vetor como o nó atual
    while(current != NULL){ //percorrendo a lista encadeada até encontrar a chave
        if(current->key ==  key){
            return current; //se encontrar o nó com essa chave, retorna o nó
        }
        current = current->next;
    }
    
    return NULL; //
}

void insertHash(HashTable *ht, long long key, long long qtd, long long *totalQuantity) {
    int index = hash(key, ht->size);  //define a posição que será inserido o nó
    
    Node *current = findNode(ht, key); //um nó current vai receber ou o nó que já existe, ou NULL, que indica que não existe ainda esse id na hash
    
    if (current != NULL) {  //se existir o nó faremos uma tratativa nas quantidades
        if (qtd < 0 && current->qtd + qtd <= 0) {
            //se a quantidade for < 0 e a quantidade somada com a quantidade adicionada ou retirada for menor ou igual a zero isso quer dizer que queremos retirar mais do que existe de itens com esse id
            *totalQuantity -= current->qtd; //então retiramos apenas a quantidade já existente desses itens, para não termos quantidades finais negativas do item.
            Node *prev = NULL; //nó anterior para mudar os apontamentos
            Node *temp = ht->table[index]; //no atual para liberarmos caso não se tenha mais uma quantidade desse item na hash
            while (temp != NULL && temp != current) {
                prev = temp;
                temp = temp->next;
            }
            if (prev == NULL) {
                ht->table[index] = current->next;
            } else {
                prev->next = current->next;
            }
            free(current); //mudamos os apontamentos e liberamos o nó
        } else { //caso a quantidade que queremos adicionar ou retirar não torne a quantidade dos itens negativos apenas atualizamos a quantidade dos itens
            *totalQuantity += qtd; //quantidade total que será printada no final do exercicio
            current->qtd += qtd; //quantidade do item na struct
        }
    } else { //se o nó não existe, inserimos ele no inicio da hash
        if (qtd > 0) { //apenas se a quantidade for maior que zero, se for menor não faz nem sentido adicionar o nó KKK
            Node *new_node = (Node *)malloc(sizeof(Node));
            new_node->key = key;
            new_node->qtd = qtd;
            new_node->next = ht->table[index]; //definindo para onde esse nó irá apontar, que seria para onde o nó no index do vetor aponta
            ht->table[index] = new_node; //mudando o nó no apontamento do index do vetor
            *totalQuantity += qtd; //atualizando a contagem que será printada no final da questão 
        }
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
    int n = 0;
    scanf("%d", &n);
    
    HashTable *ht = createHash(100003);
    
    long long totalQuantity = 0;    
    
    for(int i = 0; i < n; i++){
        long long id, qtd;
        scanf("%lld %lld", &id, &qtd);
        insertHash(ht, id, qtd, &totalQuantity);
        
    }
    
    printf("%lld", totalQuantity);
    
    freeHash(ht);
    
    
    return 0;

}