#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void) {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<ll> mp(33, 0);

        for (int i = 0; i < n; i++) {
            int a;
            cin >> a;
            int zeroes = __builtin_clz(a);
            mp[zeroes]++;
        }
        
        ll ans = 0;

        for (int i = 0; i <= 32; i++) {
            ans += mp[i] * (mp[i] - 1) / 2; // Unordered pairs, so i < j works automatically
        }

        cout << ans << "\n";
    }

    return 0;
}
