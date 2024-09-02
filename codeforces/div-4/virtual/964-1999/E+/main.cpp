#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
int pref[N];

void solve() {
    int l, r;
    cin >> l >> r;

    int res = 0, x = l;
    while (x > 0) {
        x /= 3;
        res += 2;
    }

    cout << res + pref[r] - pref[l] << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    for (int i = 1; i < N; i++) {
        int x = i;
        while (x > 0) {
            x /= 3;
            pref[i]++;
        }

        pref[i] += pref[i - 1];
    }

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}

