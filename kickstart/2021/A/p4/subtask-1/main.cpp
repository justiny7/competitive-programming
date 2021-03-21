#include <bits/stdc++.h>
using namespace std;

const int mxN = 4;
int n, a[mxN][mxN], b[mxN][mxN], row[mxN], col[mxN];

bool process(vector<pair<int, int>> have) {
    int oa[n][n];
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            oa[i][j] = a[i][j];
    for (auto [r, c] : have)
        a[r][c] = 0;
    set<int> ver[n], hor[n];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (~a[i][j])
                continue;
            hor[i].insert(j);
            ver[j].insert(i);
        }
    }
    queue<pair<int, int>> q;
    for (int i = 0; i < n; ++i) {
        if (hor[i].size() == 1) {
            int o = *hor[i].begin();
            q.emplace(i, o);
            hor[i].clear();
            ver[o].erase(i);
            a[i][o] = 0;
        }
        if (ver[i].size() == 1) {
            int o = *ver[i].begin();
            q.emplace(o, i);
            ver[i].clear();
            hor[o].erase(i);
            a[o][i] = 0;
        }
    }
    while (q.size()) {
        auto [cr, cc] = q.front(); q.pop();
        if (hor[cr].size() == 1) {
            int o = *hor[cr].begin();
            q.emplace(cr, o);
            hor[cr].clear();
            ver[o].erase(cr);
            a[cr][o] = 0;
        }
        if (ver[cc].size() == 1) {
            int o = *ver[cc].begin();
            q.emplace(o, cc);
            ver[cc].clear();
            hor[o].erase(cc);
            a[o][cc] = 0;
        }
    }
    bool ret = 1;
    for (int i = 0; i < n; ++i) {
        ret &= (ver[i].empty() && hor[i].empty());
        for (int j = 0; j < n; ++j)
            a[i][j] = oa[i][j];
    }
    return ret;
}

void solve() {
    cin >> n;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> a[i][j];
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> b[i][j];
    for (int i = 0; i < n; ++i)
        cin >> row[i];
    for (int i = 0; i < n; ++i)
        cin >> col[i];
    int tot = n * n, ans = INT_MAX;
    for (int i = 0; i < (1 << tot); ++i) {
        int here = 0;
        vector<pair<int, int>> cur;
        for (int j = 0; j < tot; ++j) {
            if (i & (1 << j)) {
                cur.emplace_back(j / n, j % n);
                here += b[j / n][j % n];
            }
        }
        if (process(cur))
            ans = min(ans, here);
    }
    cout << ans << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    for (int tc = 1; tc <= t; ++tc) {
        cout << "Case #" << tc << ": ";
        solve();
    }
}
