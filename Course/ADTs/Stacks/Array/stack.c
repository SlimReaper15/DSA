#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "stack.h"

Stack InitStack(int max_elements) {
    Stack S = (Stack)malloc(sizeof(struct StackInfo));

    assert(S != NULL);

    S->MaxElements = max_elements;

    S->StackArray = (ElementType*)malloc(S->MaxElements * sizeof(ElementType));
    assert(S->StackArray != NULL);

    S->TopIndex = -1;

    return S;
}

void Push(Stack S, ElementType E) {
    if (S->TopIndex == S->MaxElements - 1) {
        printf("Error: Stack is Full\n");
        return;
    }

    S->TopIndex++;
    S->StackArray[S->TopIndex] = E;
}

void Pop(Stack S) {
    if (IsEmpty(S)) {
        printf("Error: Stack is Empty\n");
        return;
    }

    S->TopIndex--;
}

ElementType Top(const Stack S) {
    if (IsEmpty(S)) {
        return -1; // Empty stack
    }

    return S->StackArray[S->TopIndex];
}

bool IsEmpty(const Stack S) {
    if (S->TopIndex == -1) {
        return true;
    }

    return false;
}

void ClearStack(Stack S) {
    S->TopIndex = -1;
}

void DeleteStack(Stack* SP) {
    if (*SP == NULL) {
        printf("Error: Stack does not exist\n");
        return;
    }

    free((*SP)->StackArray);
    free(*SP);
    *SP = NULL; // This is why we pass the pointer to the stack and not the stack itself, since otherwise if we call free(S) we can't set S to NULL since S no longer exists in memory
}
