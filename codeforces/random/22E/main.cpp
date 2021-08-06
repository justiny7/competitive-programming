#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 69;
int n, in_cnt, out_cnt;
int to[N], in[N], out[N];
vector<int> in_0[N], out_0[N], cmps[N];

// SCC {{{
int _scc, scc[N];
vector<int> from[N], ord;
bool vis[N];

void dfs_ord(int v) {
    vis[v] = 1;
    if (!vis[to[v]])
        dfs_ord(to[v]);
    ord.push_back(v);
}
void dfs_scc(int v) {
    scc[v] = _scc;
    for (int u : from[v])
        if (!scc[u])
            dfs_scc(u);
}
// }}}

// DSU {{{
int par[N], sz[N];
int find(int v) {
    return (v == par[v] ? v : par[v] = find(par[v]));
}
bool merge(int u, int v) {
    if ((u = find(u)) == (v = find(v)))
        return 0;
    if (sz[u] > sz[v])
        swap(u, v);
    par[u] = v, sz[v] += sz[u];
    return 1;
}
// }}}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> n;

    for (int i = 1; i <= n; ++i) {
        cin >> to[i];
        from[to[i]].push_back(i);
    }

    for (int i = 1; i <= n; ++i)
        if (!vis[i])
            dfs_ord(i);
    for (int i = n - 1; ~i; --i)
        if (!scc[ord[i]])
            ++_scc, dfs_scc(ord[i]);

    for (int i = 1; i <= n; ++i) {
        par[i] = i, sz[i] = 1;
        cmps[scc[i]].push_back(i);
    }

    if (_scc == 1) {
        cout << "0\n";
        return 0;
    }

    for (int i = 1; i <= n; ++i) {
        int u = to[i];
        if (scc[u] != scc[i]) {
            ++in[scc[u]], ++out[scc[i]];
            merge(scc[u], scc[i]);
        }
    }

    vector<int> sccs;
    for (int i = 1; i <= _scc; ++i)
        sccs.push_back(find(i));

    sort(sccs.begin(), sccs.end());
    sccs.erase(unique(sccs.begin(), sccs.end()), sccs.end());

    for (int i = 1; i <= _scc; ++i) {
        if (!in[i])
            in_0[find(i)].push_back(i), ++in_cnt;
        if (!out[i])
            out_0[find(i)].push_back(i), ++out_cnt;
    }

    for (int i = 1; i <= _scc; ++i) {
        if (in_0[i].empty())
            in_0[i].push_back(cmps[i][0]);
        if (out_0[i].empty())
            out_0[i].push_back(cmps[i][0]);
    }

    cout << max(in_cnt, out_cnt) << '\n';

    int sz = sccs.size();
    for (int i = 0; i < sz; ++i) {
        int scc_l = sccs[(i + sz - 1) % sz], scc_r = sccs[i];
        vector<int> &vl = out_0[scc_l], &vr = in_0[scc_r];

        int lptr = 0, rptr = 0;
        while (!(lptr == vl.size() - 1 && rptr == vr.size() - 1)) {
            cout << cmps[vl[lptr]][0] << " " << cmps[vr[rptr]][0] << '\n';
            if (lptr + 1 < vl.size())
                ++lptr;
            if (rptr + 1 < vr.size())
                ++rptr;
        }

        cout << cmps[vl[lptr]][0] << " " << cmps[vr[rptr]][0] << '\n';
    }
}

