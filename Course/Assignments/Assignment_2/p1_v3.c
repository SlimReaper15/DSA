#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    struct TreeNode* left;
    struct TreeNode* right;
    struct TreeNode* parent; // Implemented this for an earlier approach, but came in useful in line 155
} TreeNode;

// ---------------------------------- Queue Data Structure Implementation

typedef struct Node {
    TreeNode* node;
    struct Node* next;
} Node; // Linked List implementation of Queue

typedef struct Queue {
    Node* front;
    Node* rear;
    int size;
} Queue;

Node* createNode(TreeNode* node) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->node = node;
    newNode->next = NULL;
    return newNode;
}

void push(Queue* q, TreeNode* node) {
    Node* newNode = createNode(node);
    if (q->front == NULL && q->rear == NULL) {
        q->front = newNode;
        q->rear = newNode;
    }
    else {
        q->rear->next = newNode;
        q->rear = q->rear->next;
    }
    q->size++;
    return;
}

void pop(Queue* q) {
    if (q->front == NULL && q->rear == NULL) {
        return;
    }
    else {
        Node* temp = q->front;
        if (q->size == 1) {
            q->front = NULL;
            q->rear = NULL;
        }
        else {
            q->front = q->front->next;
        }
        q->size--;
        free(temp);
    }
}

bool empty(Queue* q) {
    if (q->size == 0) {
        return true;
    }
    return false;
}

TreeNode* front(Queue* q) {
    if (q->front == NULL) {
        return NULL;
    }
    return q->front->node;
}

TreeNode* rear(Queue* q) {
    if (q->front == NULL) {
        return NULL;
    }
    return q->rear->node;
}

/*
void push(Queue* q, TreeNode* node);
void pop(Queue* q);
bool empty(Queue* q);
TreeNode* front(Queue* q);
TreeNode* rear(Queue* q);
*/

// ---------------------------------- Queue Data Structure Implementation

TreeNode* createTreeNode(int val) {
    if (val == 1) {
        TreeNode* newTreeNode = (TreeNode*)malloc(sizeof(TreeNode));
        newTreeNode->left = NULL;
        newTreeNode->right = NULL;
        newTreeNode->parent = NULL;
        return newTreeNode;
    }
    else {
        return NULL;
    }
}
// Create a node if value is 1, and return NULL if it's 0

TreeNode* plantTree(int* a, int n) {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = NULL;
    q->rear = NULL;
    q->size = 0;

    int track = 0;

    push(q, createTreeNode(a[track++]));

    TreeNode* root = front(q);

    while (!empty(q)) {
        TreeNode* temp = front(q);
        pop(q);

        if (temp != NULL) {
            push(q, createTreeNode(a[track++]));
            temp->left = rear(q);
            if (temp->left != NULL) {
                temp->left->parent = temp;
            }
            if (track >= n) {
                break;
            }

            push(q, createTreeNode(a[track++]));
            temp->right = rear(q);
            if (temp->right != NULL) {
                temp->right->parent = temp;
            }
            if (track >= n) {
                break;
            }
        }
    }

    return root;
}
/* plantTree hehe geddit
 * This function takes the array a as input and constructs a tree from it using a queue
 * Parent node not really needed in this approach except for a small case (In line 155), but I had implemented it in an earlier approach to the problem
 * We push the first node into the queue
 * Every time we dequeue a 1 from the queue, we enqueue the next two elements of the array into the queue while setting them as the children of the dequeued element */

int ans = 0;

int solve(TreeNode* node) {
    if (node == NULL) {
        return 1;
    }
    else if (node->left == NULL && node->right == NULL) {
        return 0;
    }
    int left = solve(node->left);
    int right = solve(node->right);
    if (left == 0 || right == 0) {
        ans++;
        return 2;
    }
    else if (left == 1 && right == 1) {
        if (node->parent != NULL) {
            return 0;
        }
        else { // Can't skip 2 nodes above if the 2nd node is NULL
            ans++;
            return 2;
        }
    }
    else if (left == 2 || right == 2) {
        return 1;
    }
}
/* return 0 means that the node neither has a phone nor has access to it
 * return 1 means that the node does not have a phone but has access to it
 * return 2 means that the node has a phone 
 * Covered: Has aaccess to a phone
 * If both left and right nodes are not covered, then we give the node a phone
 * Else if both left and right node are covered, we return 0 indicating present node is not covered and move on to next node (this is the most optimal way of giving phones)
 * One exception to the above case is when the present node is the root node
 * Otherwise if either left or right node has a phone, we return 1 indiciating present node is covered */ 

int main(void) {
    int n;
    scanf("%d", &n);

    int* a = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    if (n == 1 || (n == 3 && a[1] == 0 && a[2] == 0)) {
        printf("1\n");
        return 0;
    } // Ugly ahh hardcore but ok

    TreeNode* root = plantTree(a, n);

    solve(root);

    printf("%d\n", ans);
    
    return 0;
}
