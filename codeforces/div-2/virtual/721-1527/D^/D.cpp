#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 2e5 + 69, L = 19;
int tt, dep[N], lift[N][L], sz[N], in[N], out[N];
ll n, ans[N];
vector<int> adj[N];

void dfs(int v = 0, int p = 0, int d = 0) {
    in[v] = tt++;
    dep[v] = d, lift[v][0] = p, sz[v] = 1;
    for (int i = 1; i < L; ++i)
        lift[v][i] = lift[lift[v][i - 1]][i - 1];
    for (int u : adj[v]) {
        if (u != p) {
            dfs(u, v, d + 1);
            sz[v] += sz[u];
        }
    }
    out[v] = tt++;
}
bool anc(int u, int v) {
    return (in[u] <= in[v] && out[u] >= out[v]);
}
int jump(int v, int k) {
    int ret = v;
    for (int i = L - 1; ~i; --i)
        if (k & (1 << i))
            ret = lift[ret][i];
    return ret;
}
int lca(int u, int v) {
    if (dep[u] > dep[v])
        swap(u, v);
    v = jump(v, dep[v] - dep[u]);
    if (u == v)
        return v;
    for (int i = L - 1; ~i; --i)
        if (lift[u][i] != lift[v][i])
            u = lift[u][i], v = lift[v][i];
    return lift[v][0];
}

void solve() {
    cin >> n;
    tt = 0;
    for (int i = 0; i <= n; ++i)
        adj[i].clear(), ans[i] = 0;
    for (int i = 1, u, v; i < n; ++i) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs();
    ans[0] = n * (n - 1) / 2;
    ans[1] = n * (n + 1) / 2 - 1;
    for (int u : adj[0]) {
        ll s = (u == lift[0][0] ? n - sz[u] : sz[u]);
        ans[1] -= s * (s + 1) / 2;
    }
    int ov = 0, ou = 1;
    for (int i = 2; i <= n; ++i) {
        if (dep[ov] > dep[ou])
            swap(ov, ou);
        if (lca(ou, ov) == ov)
            ans[i] = sz[ou] * (n - sz[jump(ou, dep[ou] - dep[ov] - 1)]);
        else
            ans[i] = sz[ou] * sz[ov];
        if (i == n)
            break;
        int l = lca(ov, ou);
        //cout << i << " " << ov << " " << ou << " " << l << '\n';
        if (l == ov) {
            if (anc(i, ov))
                ov = i;
            else if (anc(ou, i))
                ou = i;
            else if (lca(i, ou) == ov)
                ov = i;
            else if (!(anc(ov, i) && anc(i, ou)))
                break;
        }
        else {
            if (anc(ou, i))
                ou = i;
            else if (anc(ov, i))
                ov = i;
            else if (!((anc(l, i) && anc(i, ov)) || (anc(l, i) && anc(i, ou))))
                break;
        }
    }
    for (int i = 0; i <= n; ++i) {
        if (i < n)
            ans[i] -= ans[i + 1];
        cout << ans[i] << " \n"[i == n];
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--)
        solve();
}
