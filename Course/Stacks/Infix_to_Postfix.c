#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char c;
    struct Node* next;
} Node;

typedef struct Stack {
    Node* head;
    int top;
    int size;
} Stack;

void push(Stack* st, char c) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->c = c;
    newNode->next = st->head;
    st->head = newNode;
    st->size++;
}

void pop(Stack* st) {
    if (st->size == 0)
        return;
    Node* temp = st->head;
    st->head = st->head->next;
    free(temp);
    st->size--;
}

char top(Stack* st) {
    if (st->size == 0)
        return '\0';

    return st->head->c;
}

bool empty(Stack* st) {
    if (st->size == 0)
        return true;
    return false;
}

bool isoperator(char c) {
    if (c == '+' || c == '-' || c == '*' || c == '/')
        return true;
    return false;
}

int getWeight(char c) {
    if (c == '+' || c == '-')
        return 0;
    else
        return 1;
}

bool hasHigherPrecedence(char top, char c) {
    int w1 = getWeight(c);
    int w2 = getWeight(top);

    if (w2 >= w1)
        return true;

    return false;
}

char* toPostfix(char* expression, char* postfix) {
    int track = 0;

    Stack* st = (Stack*)malloc(sizeof(Stack));
    st->head = NULL;
    st->top = -1;
    st->size = 0;

    int n = strlen(expression);
    for (int i = 0; i < n; i++) {
        char c = expression[i];
        if (isdigit(c)) {
            postfix[track] = c;
            track++;
        }
        else if (isoperator(c)) {
            while (!empty(st) && hasHigherPrecedence(top(st), c)) {
                postfix[track] = top(st);
                track++;
                pop(st);
            }
            push(st, c);
        }
    }

    while (!empty(st)) {
        postfix[track] = top(st);
        track++;
        pop(st);
    }

    postfix[track] = '\0';

    free(st);

    return postfix;
}

int main() {
    char* expression = (char*)malloc(100 * sizeof(char));
    scanf("%s", expression);

    char *postfix = (char*)malloc(100 * sizeof(char));
    toPostfix(expression, postfix);

    printf("%s\n", postfix);
}