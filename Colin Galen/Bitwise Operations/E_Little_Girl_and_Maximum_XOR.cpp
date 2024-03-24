#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void) {
    ll l, r;
    cin >> l >> r;
    ll x = l ^ r;
    if (x == 0) {
        cout << 0 << "\n";
    }
    else {
        int pos = 64 - __builtin_clzll(x);
        cout << (1LL << pos) - 1 << "\n";
    }

    return 0;
}
