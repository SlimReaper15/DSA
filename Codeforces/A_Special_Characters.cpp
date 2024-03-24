#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        if (n % 2 == 1) {
            cout << "NO\n";
            continue;
        }
        cout << "YES\n";
        int track = 0;
        for (int i = 0; i < n / 2; i++) {
            cout << char('A' + track);
            cout << char('A' + track);
            track = (track + 1) % 26;
        }
        cout << "\n";
    }

    return 0;
}
