#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cin >> a[i][j];

    ll res = 0;
    for (int i = 0; i < m; ++i) {
        map<int, ll> pos, cnt;
        for (int j = 0, c = i + 1; j < n; ++j, c += m)
            pos[c] = j;

        ll out = 0;
        for (int j = 0; j < n; ++j) {
            if (!pos.count(a[j][i]))
                ++out;
            else
                ++cnt[(j - pos[a[j][i]] + n) % n];
        }

        ll here = LLONG_MAX;
        for (int j = 0; j < n; ++j)
            // cout << j << " " << cnt[j] << '\n',
            here = min(here, n - out - cnt[j] + j);

        // cout << "> " << i << " " << here << " " << out << '\n';
        res += here + out;
    }

    cout << res << '\n';
}

