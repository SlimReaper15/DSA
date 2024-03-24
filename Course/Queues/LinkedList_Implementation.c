// dequeue at start and enqueue at end

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* front = NULL;
Node* rear = NULL;

void enqueue(int x) {
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = x;
    temp->next = NULL;
    if (front == NULL && rear == NULL) {
        front = rear = temp;
        return;
    }

    rear->next = temp;
    rear = temp;
}

void dequeue() {
    if (front == NULL)
        return;

    Node* temp = front;
    
    if (front == rear)
        front = rear = NULL;
    else
        front = front->next;
    free(temp);
}

int Front() {
    if (front == NULL)
        return -1;
    return front->data;
}

void Print() {
    Node* temp = front;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main(){
	enqueue(2); Print(); 
	enqueue(4); Print();
	enqueue(6); Print();
	dequeue();  Print();
	enqueue(8); Print();
}