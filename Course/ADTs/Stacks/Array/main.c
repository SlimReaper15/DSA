#include <stdio.h>

#include "stack.h"

int main(void) {
    int max_elements = 1000;

    Stack S = InitStack(max_elements);

    Push(S, 10);
    Push(S, 20);
    Push(S, 30);
    Push(S, 40);

    Pop(S);

    printf("%lf\n", Top(S));

    Pop(S);
    Pop(S);

    printf("%lf\n", Top(S));

    ClearStack(S);

    printf("%lf\n", Top(S));

    DeleteStack(&S);

    return 0;
}
