#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    string s;
    cin >> n >> s;

    map<char, int> bef, aft;
    for (char c : s)
        ++aft[c];

    int res = 0;
    for (int i = 0; i < n - 1; ++i) {
        --aft[s[i]];
        if (aft[s[i]] == 0)
            aft.erase(s[i]);

        ++bef[s[i]];

        res = max(res, (int)aft.size() + (int)bef.size());
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

