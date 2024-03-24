#ifndef __STACK_H
#define __STACK_H

#include <stdbool.h>

typedef double ElementType;

struct StackInfo {
    ElementType* StackArray; // Array implementation
    int TopIndex;
    int MaxElements;
};

typedef struct StackInfo* Stack;

Stack InitStack(int max_elements);
void Push(Stack S, ElementType E);
void Pop(Stack S);
ElementType Top(const Stack S);
bool IsEmpty(const Stack S);
void ClearStack(Stack S);
void DeleteStack(Stack* S);

#endif
