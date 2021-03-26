#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k; string s;
    cin >> n >> k >> s;
    vector<int> pos;
    for (int i = 0; i < n; ++i)
        if (s[i] == '*')
            pos.push_back(i);
    n = pos.size();
    int ans = 1, lst = 0;
    for (int i = 1; i < n; ++i) {
        if (pos[i] - pos[lst] > k) {
            lst = i - 1;
            ++ans;
        }
    }
    if (pos[lst] != pos.back())
        ++ans;
    cout << ans << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--)
        solve();
}
