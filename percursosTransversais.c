#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct TreeNode {
    char value;
    struct TreeNode *left, *right;
} TreeNode;

TreeNode* createNode(char value) {
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    node->value = value;
    node->left = node->right = NULL;
    return node;
}

TreeNode* constructTree(char* preOrder, char* inOrder, int inStart, int inEnd, int* preIndex) {
    if (inStart > inEnd) {
        return NULL;
    }

    char current = preOrder[*preIndex];
    TreeNode* node = createNode(current);
    (*preIndex)++;

    if (inStart == inEnd) {
        return node;
    }

    int inIndex;
    for (inIndex = inStart; inIndex <= inEnd; inIndex++) {
        if (inOrder[inIndex] == current) {
            break;
        }
    }

    node->left = constructTree(preOrder, inOrder, inStart, inIndex - 1, preIndex);
    node->right = constructTree(preOrder, inOrder, inIndex + 1, inEnd, preIndex);

    return node;
}

void postOrderTraversal(TreeNode* root, char* result, int* index) {
    if (root == NULL) {
        return;
    }

    postOrderTraversal(root->left, result, index);
    postOrderTraversal(root->right, result, index);
    result[(*index)++] = root->value;
}

int main() {
    int testCases;
    scanf("%d", &testCases);

    while (testCases--) {
        int numNodes;
        char preOrder[53], inOrder[53]; 
        scanf("%d %s %s", &numNodes, preOrder, inOrder);

        int preIndex = 0;
        TreeNode* root = constructTree(preOrder, inOrder, 0, numNodes - 1, &preIndex);

        char result[53];
        int index = 0;
        postOrderTraversal(root, result, &index);
        result[index] = '\0';

        printf("%s\n", result);
    }

    return 0;
}
