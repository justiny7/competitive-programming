#include <bits/stdc++.h>
using namespace std;

using ll = long long;

// BIT {{{
template<class T> struct BIT {
    int sz;
    vector<T> bit;

    void init(int _sz) {
        sz = _sz;
        bit.assign(sz, 0);
    }
    void upd(int i, T x) {
        for (++i; i < sz; i += i & -i)
            bit[i] += x;
    }
    T query(int i) {
        T ret = 0;
        for (++i; i; i -= i & -i)
            ret += bit[i];
        return ret;
    }
    T query(int l, int r) {
        return query(r) - query(l - 1);
    }
};
// }}}

const int N = 2e5 + 69;
int n, t;
int tin[N], tout[N], res[N];
ll a[N], b[N];
vector<int> adj[N], pth;
BIT<ll> ft;

void dfs_prep(int v = 1) {
    tin[v] = t++;
    for (int u : adj[v])
        dfs_prep(u);
    tout[v] = t++;
}
void dfs_res(int v = 1, ll sum = 0) {
    pth.push_back(v);
    sum += a[v];

    if (v > 1) {
        int lo = 0, hi = pth.size() - 1, best = -1;
        while (lo <= hi) {
            int m = lo + hi >> 1;
            if (ft.query(tin[pth[m]]) <= sum)
                best = m, lo = m + 1;
            else
                hi = m - 1;
        }

        res[v] = best;
    }

    for (int u : adj[v])
        dfs_res(u, sum);

    pth.pop_back();
    sum -= a[v];
}

void solve() {
    cin >> n;

    for (int i = 1; i <= n; ++i)
        adj[i].clear();

    for (int i = 2; i <= n; ++i) {
        int p;
        cin >> p >> a[i] >> b[i];

        adj[p].push_back(i);
    }

    t = 0;
    dfs_prep();

    ft.init(n * 2 + 69);
    for (int i = 1; i <= n; ++i) {
        // cout << i << " " << tin[i] << " " << tout[i] << '\n';
        ft.upd(tin[i], b[i]);
        ft.upd(tout[i], -b[i]);
    }

    dfs_res();

    for (int i = 2; i <= n; ++i)
        cout << res[i] << " \n"[i == n];
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    int t;
    cin >> t;
    while (t--)
        solve();
}

