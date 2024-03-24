#ifndef HEAP_H
#define HEAP_H

#include <stdbool.h>

typedef int Element;

typedef struct Heap {
    Element* array;
    int size;
    int capacity;
} Heap;

Heap* initHeap(int capacity);
void insertIntoMaxHeap(Heap* h, Element e);
void printHeap(Heap* h);
Element deleteMaxElement(Heap* h);
void increaseMaxHeapKey(Heap* h, int index, Element newE);
Element* heapSort(Heap* h);
bool isHeapFull(Heap* h);
bool isHeapEmpty(Heap* h);

#endif
