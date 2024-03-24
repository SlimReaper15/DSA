#include <stdio.h>
#include <stdlib.h>

#include "heap.h"

Heap* createHeap(int capacity) {
    Heap* newHeap = (Heap*)malloc(sizeof(Heap));
    newHeap->capacity = capacity;
    newHeap->size = 0;
    newHeap->elements = (Element*)malloc(newHeap->capacity * sizeof(Element));

    return newHeap;
}

void insertMinHeap(Heap* H, Element E) {
    if (isHeapFull(H)) {
        return;
    }

    int index = H->size;
    H->elements[index] = E;
    H->size++;

    while (index != 0 && H->elements[index] < H->elements[(index - 1) / 2]) {
        int temp = H->elements[(index - 1) / 2];
        H->elements[(index - 1) / 2] = H->elements[index];
        H->elements[index] = temp;
        index = (index - 1) / 2;
    }
}

Element extractMin(Heap* H) {
    if (isHeapEmpty(H)) {
        return -1;
    }

    return H->elements[0];
}

void deleteFromHeap(Heap* H, Position P) {

}

void decreaseKeyHeap(Heap* H, Position P, int decreaseValue);

void increaseKeyHeap(Heap* H, Position P, int increaseValue);

bool isHeapFull(Heap* H) {
    if (H->size == H->capacity - 1) {
        return true;
    }
    return false;
}

bool isHeapEmpty(Heap* H) {
    return H->size;
}
