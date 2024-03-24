#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1e9

typedef struct TreeNode {
    bool phone;
    struct TreeNode* left;
    struct TreeNode* right;
    struct TreeNode* parent;
} TreeNode;

void addZeroes(int* a, int* n) {
    for (int i = 0; i < *n; i++) {
        if (a[i] == 0) {
            if ((2 * i) + 1 < *n && (2 * i) + 2 < *n) {
                for (int j = (*n - 1); j >= (2 * i) + 1; j--) {
                    a[j + 2] = a[j];
                }

                a[(2 * i) + 1] = 0;
                a[(2 * i) + 2] = 0;

                *n += 2;
            }
        }
    }
}
// Converts array a into an array that has index of children of a node at position 'i' at position '2i + 1' and '2i + 2'

TreeNode* createNode(void) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));

    newNode->phone = false;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->parent = NULL;

    return newNode;
}

TreeNode** createNodeArray(int* a, int n) {
    TreeNode** newNodeArray = (TreeNode**)malloc(n * sizeof(TreeNode*));

    for (int i = 0; i < n; i++) {
        if (a[i] == 0) {
            newNodeArray[i] = NULL;
        }
        else {
            newNodeArray[i] = createNode();
        }
    }

    return newNodeArray;
}

TreeNode* plantTree(TreeNode** nodeArray, int n) {
    for (int i = 0; i < n; i++) {
        if (nodeArray[i] != NULL) {
            if ((2 * i) + 1 < n) {
                nodeArray[i]->left = nodeArray[(2 * i) + 1];
            }
            else {
                nodeArray[i]->left = NULL;
            }

            if ((2 * i) + 2 < n) {
                nodeArray[i]->right = nodeArray[(2 * i) + 2];
            }
            else {
                nodeArray[i]->right = NULL;
            }
                
            if (i == 0) {
                nodeArray[i]->parent = NULL;
            }
            else {
                nodeArray[i]->parent = nodeArray[(i - 1) / 2];
            }
        }
    }
    return nodeArray[0];
}

void givePhones(TreeNode* node) {
    if (node->parent == NULL || node->parent->parent == NULL) {
        return;
    }
    else if (node->parent->parent->parent == NULL) {
        node->parent->parent->phone = true;
        return;
    }
    else {
        node->parent->parent->parent->phone = true;
        givePhones(node->parent->parent->parent);
    }
}

void givePhonesToLeaves(TreeNode* node) {
    if (node->parent->phone != true) {
        node->parent->phone = true;
        givePhones(node->parent);
    }
}

void getLeaves(TreeNode* node) {
    if (node == NULL) {
        return;
    }
    else if (node->left == NULL && node->right == NULL) {
        givePhonesToLeaves(node);
        return;
    }
    getLeaves(node->left);
    getLeaves(node->right);
}

int phoneCount = 0;

void countPhones(TreeNode* root) {
    if (root == NULL) {
        return;
    }
    if (root->phone == true) {
        phoneCount++;
    }
    countPhones(root->left);
    countPhones(root->right);
}

int main(void) {
    int n;
    scanf("%d", &n);

    int* a = (int*)malloc(MAX_SIZE * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    if (a[0] == 0) {
        printf("0\n");
        return 0;
    }

    else if (n == 1) {
        printf("1\n");
        return 0;
    }

    addZeroes(a, &n);

    TreeNode** nodeArray = createNodeArray(a, n);

    TreeNode* root = plantTree(nodeArray, n);

    getLeaves(root);

    countPhones(root);

    printf("%d\n", phoneCount);
}
