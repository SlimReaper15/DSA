#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define INT_MAX 2147483647
#define INT_MIN -INT_MAX - 1
#define MAX_SIZE 10000

typedef struct Node {
    int first;
    int second;
    bool visited;
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

    while (index != 0 && h->array[index].first > h->array[(index - 1) / 2].first) {
        Node temp = h->array[index];
        h->array[index] = h->array[(index - 1) / 2];
        h->array[(index - 1) / 2] = temp;
        index = (index - 1) / 2;
    }

    h->size++;
}

int maxIndex(int index, int left, int right) {
    if (left > right) {
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

    while((2 * index + 1 < h->size && h->array[index].first < h->array[2 * index + 1].first) || (2 * index + 2 < h->size && h->array[index].first < h->array[2 * index + 2].first)) {
        int left = INT_MIN, right = INT_MIN;
        if (2 * index + 1 < h->size) {
            left = h->array[2 * index + 1].first;
        }
        if (2 * index + 2 < h->size) {
            right = h->array[2 * index + 2].first;
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

int main(void) {
    int n, k;
    scanf("%d %d", &n, &k);

    int* x = (int*)malloc(n * sizeof(int));
    int* y = (int*)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        scanf("%d", &x[i]);
    }

    for (int i = 0; i < n; i++) {
        scanf("%d", &y[i]);
    }

    Node* node = (Node*)malloc(n * sizeof(Node));
    for (int i = 0; i < n; i++) {
        node[i].first = x[i];
        node[i].second = y[i];
        node[i].visited = false;
    }

    Heap* positivePQ = initHeap(MAX_SIZE);

    for (int i = 0; i < n; i++) {
        if (node[i].first <= k && node[i].second >= 0) {
            push(positivePQ, node[i]);
            node[i].visited = true;
        }
    }

    while (!empty(positivePQ)) {
        k += top(positivePQ);
        pop(positivePQ);

        for (int i = 0; i < n; i++) {
            if (node[i].visited == false && node[i].first <= k && node[i].second >= 0) {
                push(positivePQ, node[i]);
                node[i].visited = true;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if (node[i].visited == false && node[i].first > k) {
            printf("NO\n");
            return 0;
        }
    }

    // This is now a new problem with only negative elements left

    Heap* negativePQ = initHeap(MAX_SIZE);

    for (int i = 0; i < n; i++) {
        if (node[i].first <= k && node[i].second < 0) {
            push(negativePQ, node[i]);
            node[i].visited = true;
        }
    }

    while (!empty(negativePQ)) {
        k += top(negativePQ);
        pop(negativePQ);

        for (int i = 0; i < negativePQ->size; i++) {
            if (negativePQ->array[i].first > k) {
                printf("NO\n");
                return 0;
            }
        }

        for (int i = 0; i < n; i++) {
            if (node[i].visited == false && node[i].first <= k) {
                push(negativePQ, node[i]);
                node[i].visited = true;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if (node[i].visited == false && node[i].first > k) {
            printf("NO\n");
            return 0;
        }
    }

    if (k < 0) {
        printf("NO\n");
        return 0;
    }

    printf("YES\n");

    return 0;
}
