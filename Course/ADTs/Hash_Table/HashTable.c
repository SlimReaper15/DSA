#include <stdio.h>
#include <stdlib.h>

#include "HashTable.h"

////////////////////////////////////////////////////////////////////////////////////////////////////
// Function: CreateHashTable
// Inputs:   Table size (Max possible keys)
// Outputs:  Pointer to the HashTable which contains table size and array of linked lists inside
////////////////////////////////////////////////////////////////////////////////////////////////////

HashTable CreateHashTable(int table_size) {
    HashTable HT = (HashTable)malloc(sizeof(struct HashTableInfo));

    HT->TableSize = table_size;
    HT->head = (NodePtr*)malloc(table_size * sizeof(NodePtr));

    for (int i = 0; i < HT->TableSize; i++) {
        HT->head[i] = NULL;
    }

    return HT;
}


// Hash function which decides the key for an element (which bucket it should go into)
Key GetHash(Element E, HashTable HT) {
    if (HT->TableSize != 0) {
        return E % HT->TableSize;
    }
    else {
        printf("Error: Table size is 0\n");
        return -1;
    }
}

NodePtr FindInTable(Element E, HashTable HT) {
    Key k = GetHash(E, HT);

    NodePtr Position = HT->head[k];

    while (Position != NULL && Position->Elem != E) {
        Position = Position->next;
    }

    return Position;
}

void InsertElement(Element E, HashTable HT) {
    NodePtr Position = FindInTable(E, HT);

    if (Position == NULL) {
        Position = (NodePtr)malloc(sizeof(struct Node));
        Key k = GetHash(E, HT);
        Position->Elem = E;
        Position->next = HT->head[k];
        HT->head[k] = Position;
    }
}

int ElementCount(Element E, HashTable HT) {
    Key k = GetHash(E, HT);

    NodePtr Search = HT->head[k];

    int count = 0;

    while (Search != NULL) {
        if (Search->Elem == E) {
            count++;
        }
    }
    return count;
}

void DeleteElement(Element E, HashTable HT) {
    Key k = GetHash(E, HT);

    NodePtr Search = HT->head[k];

    while (Search != NULL) {
        if (Search->next == NULL) {
            if (Search->Elem == E) {
                free(Search);
                HT->head[k] = NULL;
                return;
            }
        }

        else if (Search->next->Elem == E) {
            NodePtr temp = Search->next;
            Search->next = Search->next->next;
            free(temp);
        }
        Search = Search->next;
    }
}


void ClearHashTable(HashTable HT) {
    for (int i = 0; i < HT->TableSize; i++) {
        NodePtr curr = HT->head[i];
        while (curr != NULL) {
            NodePtr nex = curr->next;
            free(curr);
            curr = nex;
        }
    }
}

void DeleteHashTable(HashTable HT) {
    ClearHashTable(HT);

    free(HT);
}
