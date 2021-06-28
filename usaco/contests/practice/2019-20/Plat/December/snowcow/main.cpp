#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 2e5 + 69, C = 1e5 + 69;
int n, q, t, in[N], out[N], sz[N];
set<pair<int, int>> pos[C];
vector<int> adj[N];

// BIT {{{
struct BIT {
    ll bit[N];

    BIT() {
        memset(bit, 0, sizeof(bit));
    }

    void upd(int i, ll x) {
        for (++i; i < N; i += i & -i)
            bit[i] += x;
    }
    ll query(int i) {
        ll ret = 0;
        for (++i; i; i -= i & -i)
            ret += bit[i];
        return ret;
    }
    ll query(int l, int r) {
        return query(r) - query(l - 1);
    }
} ovr, sub;
// }}}

void dfs(int v = 1, int p = 0) {
    in[v] = t++;
    sz[v] = 1;

    for (int u : adj[v]) {
        if (u != p) {
            dfs(u, v);
            sz[v] += sz[u];
        }
    }

    out[v] = t - 1;
}

int main() {
    ifstream cin("snowcow.in");
    ofstream cout("snowcow.out");

    cin >> n >> q;

    for (int i = 1, u, v; i < n; ++i) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs();

    while (q--) {
        int c; cin >> c;

        if (c & 1) {
            int v, x;
            cin >> v >> x;

            auto it = pos[x].lower_bound({in[v], -1});
            if (it != pos[x].begin() && out[prev(it)->second] >= out[v])
                continue;

            while (it != pos[x].end() && out[it->second] <= out[v]) {
                int u = it->second;
                ovr.upd(in[u], -1); ovr.upd(out[u] + 1, 1);
                sub.upd(in[u], -sz[u]);
                pos[x].erase(it++);
            }

            pos[x].emplace(in[v], v);
            ovr.upd(in[v], 1); ovr.upd(out[v] + 1, -1);
            sub.upd(in[v], sz[v]);
        }
        else {
            int v; cin >> v;
            cout << ovr.query(in[v]) * sz[v] + sub.query(in[v] + 1, out[v]) << '\n';
        }
    }
}
