#ifndef __HASHTABLE_H
#define __HASHTABLE_H

#define INVALID -6969

typedef int Key;
typedef int Element;

struct Node {
    Element Elem;
    struct Node* next;
};

typedef struct Node* NodePtr;

struct HashTableInfo {
    int TableSize;
    NodePtr* head; /* head is the starting point of an array of Node*'s, i.e, an array of linked lists */
};

typedef struct HashTableInfo* HashTable;

HashTable CreateHashTable(int table_size);
Key GetHash(Element E, HashTable HT);
NodePtr FindInTable(Element E, HashTable HT);
void InsertElement(Element E, HashTable HT);
int ElementCount(Element E, HashTable HT);
void DeleteElement(Element E, HashTable HT);
void ClearHashTable(HashTable HT);
void DeleteHashTable(HashTable HT);

#endif
