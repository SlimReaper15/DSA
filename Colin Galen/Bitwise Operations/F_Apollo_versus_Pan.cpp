#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll mod = 1000000007;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    ll t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        vector<ll> a(n);

        vector<ll> ones(60, 0);
        for (ll i = 0; i < n; i++) {
            cin >> a[i];
            
            for (ll j = 0; j < 60; j++) {
                if (((a[i] >> j) & 1) == 1) {
                    ones[j]++;
                }
            }
        }

        ll ans = 0;

        for (ll i = 0; i < n; i++) {
            ll k = a[i];
            ll andVal = 0, orVal = 0;
            for (ll j = 0; j < 60; j++) {
                ll weight = (1LL << j) % mod;
                if (((k >> j) & 1) == 1) {
                    andVal = (andVal + (weight * ones[j]) % mod) % mod;
                    orVal = (orVal + (weight * n) % mod) % mod;
                }
                else {
                    orVal = (orVal + (weight * ones[j]) % mod) % mod;
                }
            }
            ans = (ans + (andVal * orVal) % mod) % mod;
        }

        cout << ans << "\n";
    }

    return 0;
}
