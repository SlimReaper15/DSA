#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    int val;
    struct Node* left;
    struct Node* right;
} TreeNode;

TreeNode* root;

TreeNode* createNode(int val) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->val = val;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

TreeNode* Insert(TreeNode* root, int val) { // Insert val at root
    if (root == NULL) {
        root = createNode(val);
    }
    else if (val <= root->val) {
        root->left = Insert(root->left, val);
    }
    else if (val > root->val) {
        root->right = Insert(root->right, val);
    }
    return root;
}

bool Search(TreeNode* root, int val) {
    if (root == NULL) {
        return false;
    }
    else if (val == root->val) {
        return true;
    }
    else if (val < root->val) {
        Search(root->left, val);
    }
    else {
        Search(root->right, val);
    }
}

int main(void){
    // If we pass this root to any function, another pointer which points to the same block of memory as root is created
    // All tree nodes are adjusted but root will point to the same block of memory it was pointing to in main before the function was called

    root = NULL;
    Insert(root, 15);
    Insert(root, 10);
}