#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int val;
    struct Node* left;
    struct Node* right;
} Node;

Node* createNode(int val) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

Node* buildTree(int* a, int index, int n) {
    if (index >= n || a[index] == -1) {
        return NULL;
    }
    Node* node = createNode(a[index]);
    node->left = buildTree(a, (2 * index) + 1, n);
    node->right = buildTree(a, (2 * index) + 2, n);
    return node;
}

void solve(Node* root) {
    static int sum = 0;
    if (root == NULL) {
        return;
    }
    solve(root->left);
    root->val += sum;
    sum = root->val;
    solve(root->right);
}

void print(Node* root) {
    if (root == NULL) {
        return;
    }
    print(root->left);
    printf("%d ", root->val);
    print(root->right);
}

int main(void) {
    int n;
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    Node* root = buildTree(a, 0, n);

    solve(root);

    print(root);
}