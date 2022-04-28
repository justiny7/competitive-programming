#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    map<int, int> cnt;
    int res = -1;
    while (n--) {
        int x;
        cin >> x;
        ++cnt[x];

        if (cnt[x] >= 3)
            res = x;
    }
    
    cout << res << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--)
        solve();
}

