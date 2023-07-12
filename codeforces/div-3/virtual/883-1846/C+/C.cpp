#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n, m, h;
    cin >> n >> m >> h;

    vector<vector<int>> v(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j)
            cin >> v[i][j];
        
        sort(v[i].begin(), v[i].end());
    }

    vector<array<ll, 3>> res;
    for (int i = 0; i < n; ++i) {
        ll c = 0, s = 0, x = 0;
        for (int j = 0; j < m; ++j) {
            if (s + v[i][j] > h)
                break;
            x += s + v[i][j];
            s += v[i][j];
            ++c;
        }
        // cout << "> " << i << " " << c << " " << s << '\n';
        res.push_back({c, x, i});
    }

    sort(res.begin(), res.end(), [&](array<ll, 3> a, array<ll, 3> b) {
        if (a[0] > b[0])
            return true;
        else if (a[0] < b[0])
            return false;
        else if (a[1] < b[1])
            return true;
        else if (a[1] > b[1])
            return false;
        return a[2] < b[2];
    });

    // for (auto [a, b, c] : res)
        // cout << a << " " << b << " " << c << '\n';

    for (int i = 0; i < n; ++i) {
        if (res[i][2] == 0) {
            cout << i + 1 << '\n';
            return;
        }
    }
    
    assert(false);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--)
        solve();
}

