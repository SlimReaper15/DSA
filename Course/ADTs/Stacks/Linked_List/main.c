#include <stdio.h>

#include "stack.h"


int main(void) {
    Stack S = InitStack();

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
