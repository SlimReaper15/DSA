#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000000

typedef int key;
typedef int value;

typedef struct Node {
    key k;
    value v;
    struct Node* next;
} Node;

typedef struct hashMap {
    Node** buckets; // Array of linked lists
    int size;
    value defaultValue;
} hashMap;

Node* createNode(key k, value v) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->k = k;
    newNode->v = v;
    newNode->next = NULL;

    return newNode;
}

value fillDefaultValue(void) {
    return -1;
} // Change according to value type

hashMap* createHashMap(int size) {
    hashMap* mp = (hashMap*)malloc(sizeof(hashMap));
    mp->buckets = (Node**)malloc(size * sizeof(Node*));
    mp->size = size;
    mp->defaultValue = fillDefaultValue();

    for (int i = 0; i < mp->size; i++) {
        mp->buckets[i] = NULL;
    }

    return mp;
}

int hash(key k, int size) {
    return k % size;
}

void insert(hashMap* mp, key k, value v) {
    int index = hash(k, mp->size);

    Node* head = mp->buckets[index];
    while (head != NULL) {
        if (head->k == k) {
            head->v = v;
            return;
        } // Update value if the key is already present

        head = head->next;
    }

    Node* newNode = createNode(k, v);
    newNode->next = mp->buckets[index];
    mp->buckets[index] = newNode;
}

value search(hashMap* mp, key k) {
    int index = hash(k, mp->size);

    Node* head = mp->buckets[index];
    while (head != NULL) {
        if (head->k == k) {
            return head->v;
        }
        head = head->next;
    }

    return mp->defaultValue;
}

int main(void) {
    int n;
    scanf("%d", &n);

    int* a = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    hashMap* mp = createHashMap(MAX_SIZE);
    
    int max[n];
    for (int i = 0; i < n; i++) {
        max[i] = 1;
    }

    for (int i = 0; i < n; i++) {
        int temp = a[i];
        if (search(mp, temp - 1) != mp->defaultValue) {
            max[i] = max[search(mp, temp - 1)] + 1;
        }
        insert(mp, a[i], i);
    }

    int ans = 0;
    int index = -1;

    for (int i = 0; i < n; i++) {
        if (max[i] > ans) {
            ans = max[i];
            index = i;
        }
    }

    int temp = a[index];
    
    int* out = (int*)malloc(ans * sizeof(int));
    int track = 0;
    
    while (track < ans) {
        out[ans - 1 - track] = search(mp, temp);
        temp--;
        track++;
    }
    
    printf("%d\n", ans);

    for (int i = 0; i < ans; i++) {
        printf("%d ", out[i]);
    }
    printf("\n");
}
