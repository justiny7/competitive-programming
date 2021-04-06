#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 1;
int n, m, ans, par[N], sz[N];
map<int, vector<pair<int, int>>> mp;

int find(int v) {
    return (v == par[v] ? v : par[v] = find(par[v]));
}
bool merge(int a, int b) {
    a = find(a), b = find(b);
    if (a == b)
        return 0;
    if (sz[a] < sz[b])
        swap(a, b);
    par[b] = a, sz[a] += sz[b];
    return 1;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        par[i] = i, sz[i] = 1;
    while (m--) {
        int u, v, l;
        cin >> u >> v >> l;
        mp[l].emplace_back(u, v);
    }
    for (auto [w, here] : mp) {
        int cnt = here.size();
        for (auto [u, v] : here)
            if (find(u) == find(v))
                --cnt;
        for (auto [u, v] : here)
            cnt -= merge(u, v);
        ans += cnt;
    }
    cout << ans << '\n';
}
