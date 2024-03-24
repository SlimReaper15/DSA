#include <stdio.h>
#include <stdlib.h>

#include "HashTable.h"

int main() {

    int elements[10] = {0, 1, 4, 9, 16, 25, 36, 49, 64, 81};
    int searchfor[5] = {64, 67, 25, 1, 5};
    int delete[5] = {77, 78, 55, 1, 4};

    HashTable HT;

    // Creating HashTable
    HT = CreateHashTable(15000);

    // Inserting Elements in the HashTable
    for (int i = 0; i < 10; i++) {
       InsertElement(elements[i], HT);   
    }

    // Search/Find operation

    for (int i = 0; i < 5;i++) {
        printf("The element to look for is %d \n", searchfor[i]);

        if (FindInTable(searchfor[i], HT) != NULL) {
            printf("Element found in the table\n");
        }
        else {
            printf("Element not found in the table\n");            
        }
    }

    // Deleting from the HashTable
    for (int i = 0; i < 5; i++)
    {
        printf("The element to be deleted is %d\n", delete[i]);

        DeleteElement(delete[i], HT);

        if (FindInTable(delete[i], HT) != NULL) {
            printf("Element found in the table\n");
        }

        else {
            printf("Element not found in the table\n");            
        }
    }

    DeleteHashTable(HT);

    return 0;
}
