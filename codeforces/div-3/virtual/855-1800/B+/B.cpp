#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k;
    string s;
    cin >> n >> k >> s;

    map<char, int> mp;
    for (char c : s)
        ++mp[c];

    int res = 0;
    for (char l = 'a', u = 'A'; l <= 'z'; ++l, ++u) {
        int take = min(mp[l], mp[u]);
        res += take;
        mp[l] -= take;
        mp[u] -= take;

        while (k > 0 && max(mp[l], mp[u]) > 1) {
            --k, ++res;
            mp[l] -= 2, mp[u] -= 2;
        }
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

