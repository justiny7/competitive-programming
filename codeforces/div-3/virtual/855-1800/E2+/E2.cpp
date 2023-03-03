#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k;
    string s, t;
    cin >> n >> k >> s >> t;

    string ss(s), ts(t);
    sort(ss.begin(), ss.end());
    sort(ts.begin(), ts.end());

    if (ss != ts) {
        cout << "NO\n";
        return;
    }

    for (int i = 0; i < n; ++i) {
        if (i - k < 0 && i + k >= n) {
            if (s[i] != t[i]) {
                cout << "NO\n";
                return;
            }
        }
    }

    cout << "YES\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--)
        solve();
}

