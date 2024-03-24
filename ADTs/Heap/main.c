#include <stdio.h>

#include "heap.h"

#define MAX_SIZE 1000

int main(void) {
    Heap* h = initHeap(MAX_SIZE);

    insertIntoMaxHeap(h, -1);
    insertIntoMaxHeap(h, -2);
    insertIntoMaxHeap(h, -3);

    printHeap(h);

    printf("%d\n", deleteMaxElement(h));

    printHeap(h);
    
    printf("%d\n", deleteMaxElement(h));

    printHeap(h);
    return 0;
}