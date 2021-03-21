#include <bits/stdc++.h>
using namespace std;

const int mxN = 1e3 + 1;
int n, par[mxN], sz[mxN], v[mxN][mxN];

int find(int v) {
    return (v == par[v] ? v : par[v] = find(par[v]));
}
bool merge(int a, int b) {
    a = find(a), b = find(b);
    if (a == b)
        return 0;
    if (sz[a] > sz[b])
        swap(a, b);
    par[a] = b;
    sz[a] += sz[a];
    return 1;
}

void solve() {
    cin >> n;
    int ans = 0;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> v[i][j];
    vector<array<int, 3>> vec;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int x; cin >> x;
            if (~v[i][j])
                continue;
            ans += x;
            vec.push_back({x, i, j + n});
        }
    }
    for (int t = 0; t < 2; ++t)
        for (int i = 0, garbage; i < n; ++i)
            cin >> garbage;
    for (int i = 0; i < n * 2; ++i)
        par[i] = i, sz[i] = 0;
    sort(vec.rbegin(), vec.rend());
    for (auto [d, x, y] : vec)
        if (merge(x, y))
            ans -= d;
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
