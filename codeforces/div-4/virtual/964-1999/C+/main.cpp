#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, s, m;
    cin >> n >> s >> m;

    int lst = 0;
    bool f = 0;
    while (n--) {
        int l, r;
        cin >> l >> r;

        f |= (l - lst >= s);
        lst = r;
    }

    f |= (m - lst >= s);
    
    cout << (f ? "YES" : "NO") << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}

