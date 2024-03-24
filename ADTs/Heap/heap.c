#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "heap.h"

Heap* initHeap(int capacity) {
    Heap* h = (Heap*)malloc(sizeof(Heap));

    h->capacity = capacity;
    h->size = 0;
    h->array = (Element*)malloc(h->capacity * sizeof(Element));

    return h;
}

void insertIntoMaxHeap(Heap* h, Element e) {
    if (isHeapFull(h)) {
        return;
    }

    h->array[h->size] = e;

    int index = h->size;

    while (index != 0 && h->array[index] > h->array[(index - 1) / 2]) {
        int temp = h->array[index];
        h->array[index] = h->array[(index - 1) / 2];
        h->array[(index - 1) / 2] = temp;
        index = (index - 1) / 2;
    }

    h->size++;
}

Element top(Heap* h) {
    if (isHeapEmpty(h)) {
        return -1;
    }
    return h->array[0];
}

void printHeap(Heap* h) {
    for (int i = 0; i < h->size; i++) {
        printf("%d ", h->array[i]);
    }
    printf("\n");
}

int maxIndex(int index, int left, int right) {
    if (left > right) {
        return 2 * index + 1;
    }
    return 2 * index + 2;
}

Element deleteMaxElement(Heap* h) {
    if (isHeapEmpty(h)) {
        return -1;
    }
    
    int top = h->array[0];
    h->array[0] = h->array[h->size - 1];
    h->array[h->size - 1] = top;

    h->size--;

    int index = 0;

    while((2 * index + 1 < h->size && h->array[index] < h->array[2 * index + 1]) || (2 * index + 2 < h->size && h->array[index] < h->array[2 * index + 2])) {
        int left = -1, right = -1;
        if (2 * index + 1 < h->size) {
            left = h->array[2 * index + 1];
        }
        if (2 * index + 2 < h->size) {
            right = h->array[2 * index + 2];
        }

        int toSwap = maxIndex(index, left, right);

        int temp = h->array[index];
        h->array[index] = h->array[toSwap];
        h->array[toSwap] = temp;

        index = toSwap;
    }

    return top;
}

void increaseMaxHeapKey(Heap* h, int index, Element newE) {
    if (newE < h->array[index]) {
        return;
    }

    h->array[index] = newE;

    while (index > 0 && h->array[(index - 1) / 2] < h->array[index]) {
        int temp = h->array[(index - 1) / 2];
        h->array[(index - 1) / 2] = h->array[index];
        h->array[index] = temp;

        index = (index - 1) / 2;
    }
}

Element* heapSort(Heap* h) {
    Element* sorted = (Element*)malloc(h->size * sizeof(Element));
    int track = 0;
    while (!isHeapEmpty(h)) {
        sorted[track++] = deleteMaxElement(h);
    }
    return sorted;
}

bool isHeapFull(Heap* h) {
    if (h->size == h->capacity) {
        return true;
    }
    return false;
}


bool isHeapEmpty(Heap* h) {
    if (h->size == 0) {
        return true;
    }
    return false;
}
