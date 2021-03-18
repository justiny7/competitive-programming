#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    map<int, int> cnt;
    for (int i=0; i<n; ++i) {
        int x; cin >> x;
        ++cnt[x];
    }
    for (int i=0; i<n; ++i) {
        if (cnt[i]) {
            cout << i << " ";
            --cnt[i];
        }
        else
            break;
    }
    for (auto [x, t]:cnt) {
        while (t--)
            cout << x << " ";
    }
    cout << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--)
        solve();
}

