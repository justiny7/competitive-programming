#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> b(n), mn(n), mx(n);
    for (int &i : b)
        cin >> i;
    {
        set<int> used;
        int cur = 1;
        for (int i = 0; i < n; ++i) {
            int j = i;
            mn[i] = b[i];
            used.insert(b[i]);
            for (++i; i < n && b[i] == b[j]; ++i) {
                while (used.count(cur))
                    ++cur;
                mn[i] = cur;
                used.insert(cur);
            }
            --i;
        }
        for (int i = 0; i < n; ++i)
            cout << mn[i] << " \n"[i == n - 1];
    }
    {
        set<int> need;
        for (int i = 1; i <= n; ++i)
            need.insert(i);
        for (int i = 0; i < n; ++i) {
            int j = i, nxt = -1;
            mx[i] = b[i];
            need.erase(b[i]);
            for (++i; i < n && b[i] == b[j]; ++i) {
                auto it = need.lower_bound(mx[i - 1]);
                assert(it != need.begin());
                --it;
                mx[i] = *it;
                need.erase(it);
            }
            --i;
        }
        for (int i = 0; i < n; ++i)
            cout << mx[i] << " \n"[i == n - 1];
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--)
        solve();
}
