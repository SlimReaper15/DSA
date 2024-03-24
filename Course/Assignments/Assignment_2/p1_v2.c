#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    bool phone;
    bool covered;
    struct TreeNode* left;
    struct TreeNode* right;
    struct TreeNode* parent;
} TreeNode;

// ------------------------------------------------------------------ Queue Data Structure Implementation

typedef struct Node {
    TreeNode* node;
    struct Node* next;
} Node;

typedef struct Queue {
    Node* front;
    Node* rear;
    int size;
} Queue;

Node* createNode(TreeNode* node) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->node = node;
    newNode->next = NULL;
    return newNode;
}

void push(Queue* q, TreeNode* node) {
    Node* newNode = createNode(node);
    if (q->front == NULL && q->rear == NULL) {
        q->front = newNode;
        q->rear = newNode;
    }
    else {
        q->rear->next = newNode;
        q->rear = q->rear->next;
    }
    q->size++;
    return;
}

void pop(Queue* q) {
    if (q->front == NULL && q->rear == NULL) {
        return;
    }
    else {
        Node* temp = q->front;
        if (q->size == 1) {
            q->front = NULL;
            q->rear = NULL;
        }
        else {
            q->front = q->front->next;
        }
        q->size--;
        free(temp);
    }
}

bool empty(Queue* q) {
    if (q->size == 0) {
        return true;
    }
    return false;
}

TreeNode* front(Queue* q) {
    if (q->front == NULL) {
        return NULL;
    }
    return q->front->node;
}

TreeNode* rear(Queue* q) {
    if (q->front == NULL) {
        return NULL;
    }
    return q->rear->node;
}

// ------------------------------------------------------------------ Queue Data Structure Implementation

TreeNode* createTreeNode(int val) {
    if (val == 1) {
        TreeNode* newTreeNode = (TreeNode*)malloc(sizeof(TreeNode));
        newTreeNode->phone = false;
        newTreeNode->covered = false;
        newTreeNode->left = NULL;
        newTreeNode->right = NULL;
        newTreeNode->parent = NULL;
        return newTreeNode;
    }
    else {
        return NULL;
    }
}

TreeNode* plantTree(int* a, int n) {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = NULL;
    q->rear = NULL;
    q->size = 0;

    int track = 0;

    push(q, createTreeNode(a[track++]));

    TreeNode* root = front(q);

    while (!empty(q)) {
        TreeNode* temp = front(q);
        pop(q);

        if (temp != NULL) {
            push(q, createTreeNode(a[track++]));
            temp->left = rear(q);
            if (temp->left != NULL) {
                temp->left->parent = temp;
            }
            if (track >= n) {
                break;
            }

            push(q, createTreeNode(a[track++]));
            temp->right = rear(q);
            if (temp->right != NULL) {
                temp->right->parent = temp;
            }
            if (track >= n) {
                break;
            }
        }
    }

    return root;
}

void givePhones(TreeNode* node) {
    
}

void givePhonesToLeaves(TreeNode* node) {
    node->covered = true;
    if (node->parent->phone != true) {
        node->parent->phone = true;
        node->parent->parent->covered = true;
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

    int* a = (int*)malloc(n * sizeof(int));
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

    TreeNode* root = plantTree(a, n);

    getLeaves(root);

    countPhones(root);

    printf("%d\n", phoneCount);
}
