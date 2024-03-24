#include <iostream>
using namespace std;
#define MAX_SIZE 101

class stack {
    private:
        int a[MAX_SIZE];
        int top;
    public:
        stack() {
            top = -1;
        }

        void Push(int x) {
            if (top == MAX_SIZE - 1) {
                printf("Error: Stack overflow\n");
                return;
            }
            a[++top] = x;
        }

        void Pop() {
            if (top == -1) {
                printf("No element to pop\n");
                return;
            }
            top--;
        }

        int Top() {
            return a[top];
        }

        int isEmpty() {
            if (top == -1)
                return 1;

            return 0;
        }
};