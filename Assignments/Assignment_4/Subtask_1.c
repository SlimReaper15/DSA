#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define INT_MAX 2147483647
#define INT_MIN -INT_MAX - 1
#define MAX_SIZE 10000

typedef struct Node {
    int first;
    int second;
} Node;

// ----------------------------- Heap Implementation -----------------------------

typedef Node Element;

typedef struct Heap {
    Element* array;
    int size;
    int capacity;
} Heap;

Heap* initHeap(int capacity) {
    Heap* h = (Heap*)malloc(sizeof(Heap));

    h->capacity = capacity;
    h->size = 0;
    h->array = (Element*)malloc(h->capacity * sizeof(Element));

    return h;
}

bool full(Heap* h) {
    if (h->size == h->capacity) {
        return true;
    }
    return false;
}

bool empty(Heap* h) {
    if (h->size == 0) {
        return true;
    }
    return false;
}

void push(Heap* h, Element e) {
    if (full(h)) {
        return;
    }

    h->array[h->size] = e;

    int index = h->size;

    while (index != 0 && h->array[index].second < h->array[(index - 1) / 2].second) {
        Node temp = h->array[index];
        h->array[index] = h->array[(index - 1) / 2];
        h->array[(index - 1) / 2] = temp;
        index = (index - 1) / 2;
    }

    h->size++;
}

int maxIndex(int index, int left, int right) {
    if (left < right) {
        return 2 * index + 1;
    }
    return 2 * index + 2;
}

int pop(Heap* h) {
    if (empty(h)) {
        return -1;
    }
    
    Node top = h->array[0];
    h->array[0] = h->array[h->size - 1];
    h->array[h->size - 1] = top;

    h->size--;

    int index = 0;

    while((2 * index + 1 < h->size && h->array[index].second > h->array[2 * index + 1].second) || (2 * index + 2 < h->size && h->array[index].second > h->array[2 * index + 2].second)) {
        int left = INT_MIN, right = INT_MIN;
        if (2 * index + 1 < h->size) {
            left = h->array[2 * index + 1].second;
        }
        if (2 * index + 2 < h->size) {
            right = h->array[2 * index + 2].second;
        }

        int toSwap = maxIndex(index, left, right);

        Node temp = h->array[index];
        h->array[index] = h->array[toSwap];
        h->array[toSwap] = temp;

        index = toSwap;
    }

    return top.second;
}

int top(Heap* h) {
    if (empty(h)) {
        return -1;
    }
    return h->array[0].second;
}

// ----------------------------- Heap Implementation -----------------------------

int compare(const void* a, const void* b) {
    return ((Node*)a)->first - ((Node*)b)->first;
}

int main(void) {
    // int n, k, d, p;
    // scanf("%d %d %d %d", &n, &k, &d, &p);

    // int* y = (int*)malloc(n * sizeof(int));
    // int* t = (int*)malloc(n * sizeof(int));

    // for (int i = 0; i < n; i++) {
    //     scanf("%d", &y[i]);
    // }

    // for (int i = 0; i < n; i++) {
    //     scanf("%d", &t[i]);
    // }

    // Node* node = (Node*)malloc(n * sizeof(Node));
    // for (int i = 0; i < n; i++) {
    //     node[i].first = y[i];
    //     node[i].second = t[i];
    // }

    Heap* pq = initHeap(MAX_SIZE);

    Node n1 = {1, 2};
    Node n2 = {5, 3};
    Node n3 = {3, 1};

    push(pq, n1);
    push(pq, n2);
    push(pq, n3);
    
    for (int i = 0; i < pq->size; i++) {
        printf("%d ", pq->array[i].second);
    }
    // qsort(node, n, sizeof(Node), compare);
    // int stationTrack = 0;
    // int goTo = 0;
    // int prevDepth  = 0;
    // int time = 0;

    // while (goTo < d) {
    //     int nextStation = node[stationTrack].first; // depth of next station
    //     if (nextStation - goTo < k) {
    //         push(pq, node[nextStation]);
    //         k -= (nextStation - goTo);
    //         goTo = node[stationTrack++].first;
    //     }

    //     while (nextStation - goTo > k) {
    //         time += pop(pq);
    //         k += p;
    //     }

    //     if (goTo > d) {
    //         printf("%d\n", time);
    //     }

    // }

    return 0;
}
