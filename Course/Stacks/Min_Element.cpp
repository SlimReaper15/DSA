#include <iostream>
#include <stack>

using namespace std;

stack<int> st;
stack<int> stmin;

void push(int a) {
    st.push(a);
    if (stmin.empty() || a <= stmin.top())
        stmin.push(a);
}

void pop() {
    if (st.empty())
        return;
    else if (stmin.empty())
        st.pop();
    else {
        if (st.top() == stmin.top())
            stmin.pop();
        st.pop();
    }
}

int main() {
    push(4);
    push(5);
    push(8);
    pop();
    push(1);
    cout << stmin.top();
    pop();
    cout << stmin.top();
    push(-7);
    cout << stmin.top();
    push(100);
    pop();
    pop();
    cout << stmin.top();
}