#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, lst; cin >> n;
    bool f = 1;
    set<int> s;
    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        if (i == 0) {
            lst = x;
            s.insert(x);
            continue;
        }
        if (x > lst) {
            auto it = s.upper_bound(lst);
            if (it != s.end() && *it < x)
                f = 0;
        }
        else if (x < lst) {
            auto it = s.lower_bound(lst);
            if (it != s.begin() && *(--it) > x)
                f = 0;
        }
        s.insert(x);
        lst = x;
    }
    cout << (f ? "YES" : "NO") << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--)
        solve();
}
