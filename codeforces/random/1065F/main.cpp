#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 69, L = 22;
int n, k, lift[N][L], dp[N], dep[N], shallow[N], sz[N], up[N]; // shallow[i] = shallowest leaf in subtree of i
vector<int> adj[N];

void dfs(int v = 1, int d = 0) {
    dep[v] = d;

    if (adj[v].empty())
        shallow[v] = d;

    for (int u : adj[v]) {
        dfs(u, d + 1);
        shallow[v] = min(shallow[v], shallow[u]);
    }
}
void build() {
    for (int j = 1; j < L; ++j)
        for (int i = 1; i <= n; ++i)
            lift[i][j] = lift[lift[i][j - 1]][j - 1];
}
int jump(int v, int k) {
    for (int i = L - 1; ~i; --i)
        if (k & (1 << i))
            v = lift[v][i];
    return v;
}

void go(int v = 1) {
    int mx = 0;
    for (int u : adj[v]) {
        go(u);
        mx = max(mx, dp[u]);
    }

    dp[v] += mx;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> n >> k;
    for (int i = 2; i <= n; ++i) {
        cin >> lift[i][0];
        ++sz[lift[i][0]];
    }

    for (int i = 1; i <= n; ++i)
        adj[i].reserve(sz[i]);
    for (int i = 1; i <= n; ++i)
        adj[lift[i][0]].push_back(i);

    lift[1][0] = 1;
    build();

    memset(shallow, 0x3f, sizeof(shallow));
    dfs();

    for (int i = 1; i <= n; ++i) {
        int dif = shallow[i] - dep[i];
        if (dif <= k)
            up[i] = jump(i, k - dif);
    }

    for (int i = 1; i <= n; ++i)
        lift[i][0] = up[i];
    build();

    for (int i = 1; i <= n; ++i) {
        if (adj[i].size())
            continue;

        int v = i;
        for (int j = L - 1; ~j; --j)
            if (lift[v][j])
                v = lift[v][j];

        ++dp[v];
    }

    go();
    cout << dp[1] << '\n';
}
