#ifndef __STACK_H
#define __STACK_H

#include <stdbool.h>

typedef double ElementType;

struct Node {
    ElementType Elem;
    struct Node* next;
};

typedef struct Node* NodePtr;

struct StackInfo {
    NodePtr head;
};

typedef struct StackInfo* Stack;

Stack InitStack(void);
NodePtr CreateNode(ElementType E);
void Push(Stack S, ElementType E);
void Pop(Stack S);
ElementType Top(const Stack S);
bool IsEmpty(const Stack S);
void ClearStack(Stack S);
void DeleteStack(Stack* SP);

#endif
