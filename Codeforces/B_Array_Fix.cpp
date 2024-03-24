#include <bits/stdc++.h>
using namespace std;

void solve(void) {
    int n;
    cin >> n;
    vector<int> a(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for (int i = 1; i <= n; i++) {
        if (a[i - 1] > a[i]) {
            cout << "NO\n";
            return;
        }
        int x = a[i] / 10;
        int y = a[i] % 10;
        if (x < a[i - 1] || x > y) {
            continue;
        }
        a[i] = y;
    }

    cout << "YES\n";
}

int main(void) {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
