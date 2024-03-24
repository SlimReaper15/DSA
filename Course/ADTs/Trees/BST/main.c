#include <stdio.h>

#include "BST.h"

int main(void) {
    SearchTree T = NULL;

    T = CreateNode(5);
    T = Insert(T, 4);
    T = Insert(T, 6);
    T = Delete(T, 3);

    printf("%d %d %d %d %d\n", T->Elem, T->Left->Elem, T->Right->Elem, FindMin(T)->Elem, Find(T, 5)->Elem);

    return 0;
}
