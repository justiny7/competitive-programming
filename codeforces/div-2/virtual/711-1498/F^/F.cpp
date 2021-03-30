#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 1, K = 21;
int n, k, val[N], xors[N][K * 2];
vector<int> adj[N], cur[K * 2];
bool ans[N];

void dfs(int v = 1, int p = 0) {
    xors[v][0] = val[v];
    for (int u : adj[v]) {
        if (u == p)
            continue;
        dfs(u, v);
        for (int i = 0; i < k; ++i)
            xors[v][i] ^= xors[u][(i + k - 1) % k];
    }
}
void dfs2(int v = 1, int p = 0) {
    for (int u : adj[v]) {
        if (u == p)
            continue;
        for (int i = 0; i < k; ++i)
            xors[v][i] ^= xors[u][(i + k - 1) % k];
        for (int i = 0; i < k; ++i)
            xors[u][i] ^= xors[v][(i + k - 1) % k];
        dfs2(u, v);
        for (int i = 0; i < k; ++i)
            xors[u][i] ^= xors[v][(i + k - 1) % k];
        for (int i = 0; i < k; ++i)
            xors[v][i] ^= xors[u][(i + k - 1) % k];
    }
    int here = 0;
    for (int i = k / 2; i < k; ++i)
        here ^= xors[v][i];
    if (here)
        ans[v] = 1;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> k, k *= 2;
    for (int i = 1; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for (int i = 1; i <= n; ++i)
        cin >> val[i];
    dfs(); dfs2();
    for (int i = 1; i <= n; ++i)
        cout << ans[i] << " \n"[i == n];
}
