#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 669;
int n, m, q;
vector<pair<int, int>> qu[N];
vector<array<ll, 4>> edges;
ll d[N][N], cur[N];
bool ok[N * N], vis[N];

int main() {
    memset(d, 0x3f, sizeof(d));
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int a, b; ll c;
        cin >> a >> b >> c;
        d[a][b] = d[b][a] = c;
        edges.push_back({a, b, c, i});
    }
    for (int i = 1; i <= n; ++i)
        d[i][i] = 0;
    for (int k = 1; k <= n; ++k)
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
    cin >> q;
    while (q--) {
        int u, v; ll w;
        cin >> u >> v >> w;
        qu[v].emplace_back(u, w);
        qu[u].emplace_back(v, w);
    }
    for (int st = 1; st <= n; ++st) {
        memset(cur, 0x3f, sizeof(cur));
        memset(vis, 0, sizeof(vis));
        for (auto [en, len] : qu[st])
            cur[en] = -len;
        for (int t = 0; t < n; ++t) {
            int nxt = -1;
            for (int v = 1; v <= n; ++v)
                if (!vis[v] && (nxt < 0 || cur[nxt] > cur[v]))
                    nxt = v;
            vis[nxt] = 1;
            for (int v = 1; v <= n; ++v)
                if (!vis[v])
                    cur[v] = min(cur[v], cur[nxt] + d[v][nxt]);
        }
        for (auto [u, v, w, ind] : edges)
            if (cur[v] <= -w - d[u][st])
                ok[ind] = 1;
    }
    int ans = 0;
    for (int i = 0; i < m; ++i)
        ans += ok[i];
    cout << ans << '\n';
}
