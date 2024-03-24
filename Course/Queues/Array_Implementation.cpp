#include <iostream>
using namespace std;

#define MAX_SIZE 101

class Queue {
    private:
        int a[MAX_SIZE];
        int front, rear;

    public:
        Queue() {
            front = rear = -1;
        }

        int isEmpty() {
            if (front == -1 && rear == -1)
                return 1;
            
            return 0;
        }
        
        int isFull() {
            if ((rear + 1) % MAX_SIZE == front)
                return 1;
            
            return 0;
        }

        void enqueue(int x) {
            if (isFull())
                return;

            else if (isEmpty()) {
                front = rear = 0;
                a[rear] = x;
            }
            else {
                rear = (rear + 1) % MAX_SIZE;
                a[rear] = x;
            }
        }

        void dequeue() {
            if (isEmpty())
                return;
            else if (front == rear)
                front = rear = -1;
            else
                front = (front + 1) % MAX_SIZE;
        }

        int top() {
            if (front == -1)
                return -1;

            return a[front];
        }

        void Print() {
            int n = (rear - front + MAX_SIZE) % MAX_SIZE + 1;
            for (int i = 0; i < n; i++)
                cout << a[(front + i) % MAX_SIZE] << " ";

            cout << "\n";
        }
};

int main() {
   Queue Q; // creating an instance of Queue. 
   Q.enqueue(2);  Q.Print();  
   Q.enqueue(4);  Q.Print();  
   Q.enqueue(6);  Q.Print();
   Q.dequeue();	  Q.Print();
   Q.enqueue(8);  Q.Print();
}