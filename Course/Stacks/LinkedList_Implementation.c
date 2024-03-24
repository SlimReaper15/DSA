#include <stdio.h>

typedef struct Node {
    int data;
    Node* next;
} Node;

Node* top = NULL;

void Push(int x) {
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = x;
    temp->next = top;
    top = temp;
}

void Pop() {
    if (top == NULL)
        return;
    
    Node *temp;
    temp = top;
    top = top->next;
    free(temp);
}