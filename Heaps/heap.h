#ifndef HEAP_H
#define HEAPH_H

#include <stdbool.h>

typedef int Element;
typedef unsigned int Position;

typedef struct Heap {
    Element* elements;
    int size;
    int capacity;
} Heap;

Heap* createHeap(int capacity);
void insertMinHeap(Heap* H, Element E);
Element extractMin(Heap* H);
void deleteFromHeap(Heap* H, Position P);
void decreaseKeyHeap(Heap* H, Position P, int decreaseValue);
void increaseKeyHeap(Heap* H, Position P, int increaseValue);
bool isHeapFull(Heap* H);
bool isHeapEmpty(Heap* H);

#endif
