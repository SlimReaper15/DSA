#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int t;
    cin >> t;
    
    while (t--) {
        string s;
        cin >> s;
        
        string pal = "";

        stack<char> st;
        int flag1 = 0;
        int brack = 0;

        for (char c : s) {
            if (isalpha(c)) {
                pal += c;
            }
            else if (flag1 == 0) {
                if (c == '(' || c == '[' || c == '{') {
                    brack = 1;
                    st.push(c);
                }
                else if (st.empty() || (c == ')' && st.top() != '(') || (c == ']' && st.top() != '[') || (c == '}' && st.top() != '{')) {
                    flag1 = 1;
                }
                else {
                    st.pop();
                }
            }
        }
        
        int n = pal.length();
        int flag2 = 0;

        for (int i = 0; i < n / 2; i++) {
            if (pal[i] != pal[n - 1 - i]) {
                flag2 = 1;
            }
        }

        if (brack == 1 && flag1 == 0 && flag2 == 0) {
            cout << "Balanced and Palindromic\n";
        }
        else if (brack == 1 && flag1 == 0) {
            cout << "Balanced\n";
        }
        else if (flag2 == 0) {
            cout << "Palindromic\n";
        }
        else {
            cout << -1 << "\n";
        }
    }
}
