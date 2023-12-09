#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


struct TreeNode {
    char data[20];
    struct TreeNode* left;
    struct TreeNode* right;
};

struct TreeNode* createNode(char data[]) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    if (newNode == NULL) {
        printf("Memory allocation failed!");
        exit(1);
    }
    
    strcpy(newNode->data, data);
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct TreeNode* readTree() {
    int data;
    printf("Enter data (or -1 for no node): ");
    scanf("%d", &data);

    if (data == -1) {
        return NULL;
    }

    struct TreeNode* newNode = createNode(data);

    printf("Enter left child of %d:\n", data);
    newNode->left = readTree();

    printf("Enter right child of %d:\n", data);
    newNode->right = readTree();

    return newNode;
}

int main() {
    struct TreeNode* root = readTree();
    for(int i = 0; i < 10; i++)
        printf("%s\n", (root+i)->data);
    return 0;
}
