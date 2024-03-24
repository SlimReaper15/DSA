#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void) {
    int n;
    cin >> n;

    unordered_map<ll, ll> mp;
    ll ans = 0;

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;

        ll mask = 0;
        
        for (char c : s) {
            mask ^= (1 << (c - 'a'));
        }

        ans += mp[mask];

        for (int flip = 0; flip < 26; flip++) {
            mask ^= (1 << flip);
            ans += mp[mask];
            mask ^= (1 << flip);
        }

        mp[mask]++;
    }

    cout << ans << "\n";

    return 0;
}
