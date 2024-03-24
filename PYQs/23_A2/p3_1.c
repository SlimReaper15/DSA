#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 500


typedef struct Node {
    int val;
    struct Node* left;
    struct Node* right;
} Node;

typedef struct queue {
    Node* a[MAX_SIZE];
    int front;
    int rear;
    int size;
} queue;

void push(queue* q, Node* val) {
    if (q->size == 0) {
        q->front = 0;
        q->rear = -1;
    }
    q->a[++(q->rear)] = val;
    q->size++;
}

void pop(queue* q) {
    if (q->size == 1) {
        q->front = q->rear = -1;
    }
    (q->front)++;
    q->size--;
}

Node* front(queue* q) {
    return q->a[q->front];
}

Node* createNode(int val) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->val = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* buildTree(int* arr, int index, int n) {
    if (index >= n || arr[index] == -1) {
        return NULL;
    }
    Node* node = createNode(arr[index]);
    node->left = buildTree(arr, (2 * index) + 1, n);
    node->right = buildTree(arr, (2 * index) + 2, n);
    return node;
}

int main(void) {
    int n;
    scanf("%d", &n);
    int* a = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    Node* root = buildTree(a, 0, n);

    queue* q = (queue*)malloc(sizeof(queue));
    q->front = -1;
    q->rear = -1;
    q->size = 0;

    push(q, root);

    int odd = 0;

    int ans[100];
    int track = 0;

    int temp1[40];
    int temp1Track = 0;

    while (q->size != 0) {
        int n = q->size;
        for (int i = 0; i < n; i++) {
            Node* temp = front(q);
            pop(q);
            temp1[temp1Track++] = temp->val;
            if (temp->left != NULL) {
                push(q, temp->left);
            }
            if (temp->right != NULL) {
                push(q, temp->right);
            }
        }
        if (odd % 2 == 0) {
            for (int i = 0; i < temp1Track; i++) {
                ans[track++] = temp1[i];
            }
        }
        else {
            for (int i = temp1Track - 1; i >= 0; i--) {
                ans[track++] = temp1[i];
            }
        }
        temp1Track = 0;
        odd++;
    }

    for (int i = 0; i < track; i++) {
        printf("%d ", ans[i]);
    }
    printf("\n");

    return 0;
}