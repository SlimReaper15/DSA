#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll mod = 1000000007;

int main(void) {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        
        ll ans = 1;
        for (int i = 0; i < k; i++) {
            ans = (ans * n) % mod;
        }

        cout << ans << "\n";
    }

    return 0;
}
