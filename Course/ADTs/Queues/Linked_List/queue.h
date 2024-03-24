#ifndef __QUEUE_H
#define __QUEUE_H

#include <stdbool.h>

typedef int ElementType;

struct Node {
    ElementType Elem;
    struct Node* next;
};

typedef struct Node* NodePtr;

struct QueueInfo {
    NodePtr front;
    NodePtr rear;
    int size;
};

typedef struct QueueInfo* Queue;

NodePtr createNode(ElementType E);
Queue InitQueue(void);
void EnQueue(Queue Q, ElementType E);
ElementType DeQueue(Queue Q);
ElementType Front(Queue Q);
bool IsEmpty(Queue Q);
void ClearQueue(Queue Q);
void DeleteQueue(Queue* QP);
void PrintQueue(Queue Q);

#endif
