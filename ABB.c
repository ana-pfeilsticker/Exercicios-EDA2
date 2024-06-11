#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 5000

typedef struct Node {
    int leftChild;
    int rightChild;
} Node;

Node tree[MAX_NODES];
int isBalanced = 1;

int calculateHeight(int nodeIndex) {
    if (nodeIndex == -1) return 0;

    int leftHeight = calculateHeight(tree[nodeIndex].leftChild);
    int rightHeight = calculateHeight(tree[nodeIndex].rightChild);

    if (abs(leftHeight - rightHeight) > 1) isBalanced = 0;

    return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
}

int main() {
    int numNodes;
    scanf("%d", &numNodes);

    if (numNodes == 1) {
        printf("Sim\n");
        return 0;
    }

    for (int i = 0; i < MAX_NODES; i++) {
        tree[i].leftChild = -1;
        tree[i].rightChild = -1;
    }

    int parentNode;
    for (int i = 2; i <= numNodes; i++) {
        scanf("%d", &parentNode);
        if (tree[parentNode].leftChild == -1) {
            tree[parentNode].leftChild = i;
        } else {
            tree[parentNode].rightChild = i;
        }
    }

    calculateHeight(1); // Começa do nó raiz (1)
    printf("%s\n", isBalanced ? "Sim" : "Nao");

    return 0;
}
