#include <bits/stdc++.h>
using namespace std;

void solve(void) {
    int n;
    cin >> n;

    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < n - 2; i++) {
        if (a[i] < 0) {
            printf("NO\n");
            return;
        }
        int curr = a[i];
        a[i] -= curr;
        a[i + 1] -= 2 * curr;
        a[i + 2] -= curr;
    }

    if (a[n - 2] != 0 || a[n - 1] != 0) {
        printf("NO\n");
        return;
    }
    printf("YES\n");
}

int main(void) {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
