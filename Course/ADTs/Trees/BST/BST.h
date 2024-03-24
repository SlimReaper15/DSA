#ifndef __BST_H
#define __BST_H

typedef int ElementType;

struct TreeNode {
    ElementType Elem;
    struct TreeNode* Left;
    struct TreeNode* Right;
};

typedef struct TreeNode* SearchTree;

SearchTree CreateNode(ElementType E);
SearchTree Insert(SearchTree T, ElementType E);
SearchTree Delete(SearchTree T, ElementType E);
SearchTree Find(SearchTree T, ElementType E);
SearchTree FindMin(SearchTree T);

#endif
