#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define element_type Node*
#define MAX_SIZE 1000

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct Stack {
    element_type ele[MAX_SIZE];
    int top;
    int size;
} Stack;

void push(Stack* st, element_type x) {
    if (st->size == MAX_SIZE - 1)
        return;

    st->top++;
    st->ele[st->top] = x;
    st->size++;
}

void pop(Stack* st) {
    if (st->size == 0)
        return;
    
    st->top--;
    st->size--;
}

element_type top(Stack* st) {
    if (st->size == 0)
        return NULL; // Change according to element type

    return st->ele[st->top];
}

bool empty(Stack* st) {
    if (st->size == 0)
        return true;
    else
        return false;
}

int main() {
    Stack* st = (Stack*)malloc(sizeof(Stack));
    st->top = -1;
    st->size = 0;

    Node* head = NULL;
    Node* tail;

    for (int i = 0; i < 5; i++) {
        Node* newNode = (Node*)malloc(sizeof(Node));
        int a;
        scanf("%d", &a);
        newNode->data = a;
        newNode->next = NULL;
        if (head == NULL) {
            head = newNode;
            tail = newNode;
        }
        else {
            tail->next = newNode;
            tail = newNode;
        }
    } // Input linked list with head head
    
    Node* temp = head;

    while (temp != NULL) {
        push(st, temp);
        temp = temp->next;
    } // Push the nodes into the stack

    temp = top(st);
    head = temp;
    pop(st);

    while (!empty(st)) {
        temp->next = top(st);
        pop(st);
        temp = temp->next;
    }
    temp->next = NULL;

    temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}