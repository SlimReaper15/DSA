#ifndef __AVL_H
#define __AVL_H

typedef int ElementType;

struct AVLNode {
    ElementType Element;
    struct AVLNode* Left;
    struct AVLNode* Right;
    int Height;
};

typedef struct AVLNode* AVLTree;

AVLTree Insert(AVLTree T, ElementType E);
AVLTree Delete(AVLTree T, ElementType E);
AVLTree Find(AVLTree T, ElementType E);
AVLTree FindMin(AVLTree T);
AVLTree FindMax(AVLTree T);
ElementType GetElement(AVLTree T);

#endif
