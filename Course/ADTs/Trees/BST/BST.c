#include <stdio.h>
#include <stdlib.h>

#include "BST.h"

SearchTree CreateNode(ElementType E) {
    SearchTree newNode = (SearchTree)malloc(sizeof(struct TreeNode));
    newNode->Elem = E;
    newNode->Left = NULL;
    newNode->Right = NULL;
    
    return newNode;
}

SearchTree Insert(SearchTree T, ElementType E) {
    if (T == NULL) {
        T = CreateNode(E);
    }
    else if (E > T->Elem) {
        T->Right = Insert(T->Right, E);
    }
    else if (E < T->Elem) {
        T->Left = Insert(T->Left, E);
    }
    return T;
}

SearchTree Delete(SearchTree T, ElementType E) {
    if (T == NULL) {
        return T;
    }
    if (E > T->Elem) {
        T->Right = Delete(T->Right, E);
    }
    else if (E < T->Elem) {
        T->Left = Delete(T->Left, E);
    }
    else {
        if (T->Left == NULL && T->Right == NULL) {
            free(T);
            T = NULL;
        }
        else if (T->Left == NULL) {
            SearchTree temp = T;
            T = T->Right;
            free(temp);
        }
        else if (T->Right == NULL) {
            SearchTree temp = T;
            T = T->Left;
            free(temp);
        }
        else {
            int min = FindMin(T->Right)->Elem;
            T->Elem = min;
            T->Right = Delete(T->Right, min);
        }
    }
    return T;
}

SearchTree Find(SearchTree T, ElementType E) {
    if (T == NULL) {
        return T;
    }
    else if (E > T->Elem) {
        return Find(T->Right, E);
    }
    else if (E < T->Elem) {
        return Find(T->Left, E);
    }
    else {
        return T;
    }
}

SearchTree FindMin(SearchTree T) {
    if (T == NULL || T->Left == NULL) {
        return T;
    }

    return FindMin(T->Left);
}
