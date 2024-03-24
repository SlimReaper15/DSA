#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "queue.h"

Queue InitQueue(void) {
    Queue Q = (Queue)malloc(sizeof(struct QueueInfo));
    Q->front = NULL;
    Q->rear = NULL;
    Q->size = 0;

    return Q;
}

NodePtr createNode(ElementType E) {
    NodePtr newNode = (NodePtr)malloc(sizeof(struct Node));
    newNode->Elem = E;
    newNode->next = NULL;
    return newNode; 
}

void EnQueue(Queue Q, ElementType E) {
    NodePtr newNode = createNode(E);

    if (IsEmpty(Q)) {
        Q->front = Q->rear = newNode;
        Q->size++;
        return;
    }

    Q->rear->next = newNode;
    Q->rear = Q->rear->next;
    Q->size++;
}

ElementType DeQueue(Queue Q) {
    if (IsEmpty(Q)) {
        printf("Error: Queue is Empty\n");
        return -1;
    }

    NodePtr temp = Q->front;
    int deleted = temp->Elem;

    if (Q->size == 1) {
        Q->front = NULL;
        Q->rear = NULL;
    }

    else {
        Q->front = Q->front->next;
    }

    free(temp);

    Q->size--;

    return deleted;
}

ElementType Front(Queue Q) {
    if (IsEmpty(Q)) {
        return -1;
    }

    return Q->front->Elem;
}

bool IsEmpty(Queue Q) {
    if (Q->size == 0) {
        return true;
    }
    return false;
}

void ClearQueue(Queue Q) {
    Q->front = NULL;
    Q->rear = NULL;
    Q->size = 0;
}

void DeleteQueue(Queue* QP) {
    if (*QP == NULL) {
        printf("Error: Queue does not exist\n");
        return;
    }

    NodePtr temp = (*QP)->front;

    while (temp != NULL) {
        NodePtr del = temp;
        temp = temp->next;
        free(del);
    }

    (*QP)->front = NULL;
    (*QP)->rear = NULL;

    free(*QP);

    *QP = NULL;
}

void PrintQueue(Queue Q) {
    if (Q->size == 0) {
        printf("Error: Queue is Empty\n");
        return;
    }

    NodePtr temp = Q->front;

    while (temp != NULL) {
        printf("%d ", temp->Elem);
        temp = temp->next;
    }

    printf("\n");
}
