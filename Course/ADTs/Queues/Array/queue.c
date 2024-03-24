#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "queue.h"

Queue InitQueue(int queue_capacity) {
    Queue Q = (Queue)malloc(sizeof(struct QueueInfo));
    assert(Q != NULL);

    assert(queue_capacity > 0);
    Q->Capacity = queue_capacity;

    Q->QueueArray = (ElementType*)malloc(Q->Capacity * sizeof(ElementType));
    assert(Q->QueueArray != NULL);

    Q->Size = 0;
    Q->Front = 0;
    Q->Rear = -1;

    return Q;
}

void EnQueue(Queue Q, ElementType E) {
    if (IsFull(Q)) {
        printf("Error: Queue is Full\n");
        return;
    }

    Q->Rear = (Q->Rear + 1) % Q->Capacity;
    Q->QueueArray[Q->Rear] = E;
    Q->Size++;
}

ElementType DeQueue(Queue Q) {
    if (IsEmpty(Q)) {
        printf("Error: Queue is Empty\n");
        return -1;
    }

    ElementType deleted = Q->QueueArray[Q->Front];

    Q->Front = (Q->Front + 1) % Q->Capacity;
    Q->Size--;

    return deleted;
}

bool IsEmpty(Queue Q) {
    if (Q->Size == 0) {
        return true;
    }

    return false;
}

bool IsFull(Queue Q) {
    if (Q->Size == Q->Capacity) {
        return true;
    }

    return false;
}

void ClearQueue(Queue Q) {
    Q->Size = 0;
    Q->Front = 0;
    Q->Rear = -1;
}

void DeleteQueue(Queue* QP) {
    if (*QP == NULL) {
        printf("Error: Queue does not exist\n");
        return;
    }

    free((*QP)->QueueArray);
    free(*QP);
    *QP = NULL;
}

void PrintQueue(Queue Q) {
    for (int i = 0; i < Q->Size; i++) {
        printf("%d ", Q->QueueArray[(Q->Front + i) % Q->Capacity]);
    }
    printf("\n");
}
