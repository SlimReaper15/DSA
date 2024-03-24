#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    int n;
    struct Node* next;
} Node;

typedef struct Stack {
    Node* head;
    int top;
    int size;
} Stack;

void push(Stack* st, int n) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->n = n;
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

int top(Stack* st) {
    if (st->size == 0)
        return -1;

    return st->head->n;
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

int evaluate(int op1, int op2, char c) {
    if (c == '+')
        return op1 + op2;
    else if (c == '-')
        return op1 - op2;
    else if (c == '*')
        return op1 * op2;
    else
        return op1 / op2;
}

int evaluatePostfix(char* expression) {
    Stack* st = (Stack*)malloc(sizeof(Stack));
    st->top = -1;
    st->size = 0;

    int n = strlen(expression);
    for (int i = 0; i < n; i++) {
        char c = expression[i];
        if (isdigit(c)) {
            int a = c - '0';
            push(st, a);
        }
        else if (isoperator(c)) {
            int op2 = top(st);
            pop(st);
            int op1 = top(st);
            pop(st);
            int res = evaluate(op1, op2, c);
            push(st, res);
        }
    }
    return top(st);
}

int main() {
    char* expression = (char*)malloc(100 * sizeof(char));
    scanf("%s", expression);

    printf("%d\n", evaluatePostfix(expression));
}