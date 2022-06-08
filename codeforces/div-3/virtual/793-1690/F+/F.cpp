#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n;
    string s;
    cin >> n >> s;

    vector<int> p(n);
    for (int &i : p)
        cin >> i, --i;

    ll res = 1;
    vector<char> vis(n);
    for (int i = 0; i < n; ++i) {
        if (vis[i])
            continue;

        string here;
        int cur = i;
        while (!vis[cur]) {
            vis[cur] = 1;
            here += s[cur];
            cur = p[cur];
        }

        // cout << here << '\n';

        string test = here;
        ll c = 0;
        do {
            ++c;
            rotate(test.begin(), test.begin() + 1, test.end());
        } while (test != here);

        // cout << c << " " << '\n';

        res = lcm(res, c);
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

