#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "stack.h"

Stack InitStack(void) {
    Stack S = (Stack)malloc(sizeof(struct StackInfo));
    S->head = NULL;

    return S;
}

NodePtr CreateNode(ElementType E) {
    NodePtr newNode = (NodePtr)malloc(sizeof(struct Node));

    newNode->Elem = E;
    newNode->next = NULL;

    return newNode;
}

void Push(Stack S, ElementType E) {
    NodePtr newNode = CreateNode(E);
    
    newNode->next = S->head;
    S->head = newNode;
}

void Pop(Stack S) {
    if (S->head == NULL) {
        printf("Error: Stack is Empty\n");
        return;
    }

    NodePtr temp = S->head;
    S->head = S->head->next;
    free(temp);
}

ElementType Top(const Stack S) {
    if (S->head == NULL) {
        return -1;
    }

    return S->head->Elem;
}

bool IsEmpty(const Stack S) {
    if (S->head == NULL) {
        return true;
    }

    return false;
}

void ClearStack(Stack S) {
    S->head = NULL;
}

void DeleteStack(Stack* SP) {
    if (*SP == NULL) {
        printf("Error: Stack does not exist\n");
        return;
    }
    
    NodePtr temp = (*SP)->head;

    while (temp != NULL) {
        NodePtr del = temp;
        temp = temp->next;
        free(del);
    }

    (*SP)->head = NULL;

    free((*SP));

    *SP = NULL;
}
