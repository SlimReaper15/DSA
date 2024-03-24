#include <iostream>
#include <stack>
using namespace std;

void reverse(string& s) {
    stack<char> c;
    int n = s.length();
    for (int i = 0; i < n; i++)
        c.push(s[i]);
    
    for (int i = 0; i < n; i++) {
        s[i] = c.top();
        c.pop();
    }
}

int main() {
    string s;
    cin >> s;
    reverse(s);
    cout << s;
}