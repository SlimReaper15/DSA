#include "queue.h"

int main(void) {
    Queue Q = InitQueue(100);

    EnQueue(Q, 10);
    PrintQueue(Q);

    EnQueue(Q, 20);
    PrintQueue(Q);

    EnQueue(Q, 30);
    PrintQueue(Q);

    EnQueue(Q, 40);
    PrintQueue(Q);

    DeQueue(Q);
    PrintQueue(Q);

    DeQueue(Q);
    PrintQueue(Q);

    ClearQueue(Q);
    PrintQueue(Q);

    DeleteQueue(&Q);

    return 0;
}
