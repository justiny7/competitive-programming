#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int N = 2e5 + 69;
int n, m;
ll par[N], pos[N];
set<ll> s[N];

int find(int v) {
    return (v == par[v] ? v : par[v] = find(par[v]));
}
bool merge(int u, int v, int d) {
    int ou = u, ov = v;
    u = find(u), v = find(v);
    if (u == v)
        return 0;

    if (s[u].size() > s[v].size()) {
        swap(u, v);
        swap(ou, ov);
        d = -d;
    }

    ll shift = pos[ov] - pos[ou] - d;
    for (int x : s[u]) {
        pos[x] += shift;
        s[v].insert(x);
    }

    s[u].clear();
    par[u] = v;

    return 1;
}

void solve() {
    cin >> n >> m;

    for (int i = 1; i <= n; ++i) {
        par[i] = i, pos[i] = LLONG_MAX;
        s[i].clear();
        s[i].insert(i);
    }

    bool f = 0;
    while (m--) {
        int a, b, d;
        cin >> a >> b >> d;

        if (pos[a] == LLONG_MAX && pos[b] == LLONG_MAX)
            pos[a] = 0, pos[b] = d;
        else if (pos[b] == LLONG_MAX)
            pos[b] = pos[a] + d;
        else if (pos[a] == LLONG_MAX)
            pos[a] = pos[b] - d;

        if (!merge(a, b, d) && pos[b] - pos[a] != d)
            f = 1;

        if (!f)
            assert(pos[b] - pos[a] == d);

        /*
        cout << "> " << a << " " << b << " " << d << '\n';
        for (int i = 1; i <= n; ++i)
            cout << i << " " << pos[i] << '\n';
        cout << '\n';
        */
    }

    cout << (f ? "NO" : "YES") << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--)
        solve();
}

