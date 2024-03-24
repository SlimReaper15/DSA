#ifndef __QUEUE_H
#define __QUEUE_H

#include <stdbool.h>

typedef int ElementType;

struct QueueInfo {
    ElementType* QueueArray;
    int Front;
    int Rear;
    int Size;
    int Capacity;
};

typedef struct QueueInfo* Queue;

Queue InitQueue(int queue_capacity);
void EnQueue(Queue Q, ElementType E);
ElementType DeQueue(Queue Q);
bool IsEmpty(Queue Q);
bool IsFull(Queue Q);
void ClearQueue(Queue Q);
void DeleteQueue(Queue* QP);
void PrintQueue(Queue Q);

#endif
