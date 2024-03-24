#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned long long int ull;

typedef struct hashNode {
    ull hash;
    char str[11];
    struct hashNode* next;
} hashNode;

typedef struct hashMap {
    hashNode** buckets;
    int size;
} hashMap;

hashMap* createHashMap(int size) {
    hashMap* mp = (hashMap*)malloc(sizeof(hashMap));
    mp->buckets = (hashNode**)malloc(size * sizeof(hashNode*));
    mp->size = size;

    for (int i = 0; i < mp->size; i++) {
        mp->buckets[i] = NULL;
    }

    return mp;
}

ull getHash(char* str) {
    int primes[26] = {2, 3 , 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101};
    ull lol = 1;
    int n = strlen(str);
    for (int i = 0; i < n; i++) {
        lol *= primes[str[i] - 'a'];
    }
    return lol;
}

void insert(hashMap* mp, ull key, char* s) {
    ull index = key % mp->size;

    hashNode* newNode = (hashNode*)malloc(sizeof(hashNode));
    newNode->hash = key;
    strcpy(newNode->str, s);
    newNode->next = mp->buckets[index];
    mp->buckets[index] = newNode;
}

int main(void) {
    int n, q;
    scanf("%d %d", &n, &q);

    hashMap* mp = createHashMap(100);

    while (n--) {
        char s[11];
        scanf("%s", s);
        insert(mp, getHash(s), s);
    }

    while (q--) {
        char s[11];
        scanf("%s", s);
        hashNode* head = mp->buckets[getHash(s) % mp->size];
        if (head == NULL) {
            printf("-1\n");
            continue;
        }
        while (head != NULL) {
            printf("%s ", head->str);
            head = head->next;
        }
        printf("\n");
    }
}