#include <bits/stdc++.h>
using namespace std;

const int N = 4e5 + 69;
int n, m, scc[N], in[N], scnt, ccnt, ans;
vector<int> pos[N], adj[N], radj[N], topo;
bool vis[N];

inline void add(int u, int v) {
    adj[u].push_back(v);
    radj[v].push_back(u);
}

void dfs(int v) {
    vis[v] = 1;
    for (int u : adj[v])
        if (!vis[u])
            dfs(u);
    topo.push_back(v);
}
void dfs2(int v) {
    scc[v] = scnt;
    for (int u : radj[v])
        if (!scc[u])
            dfs2(u);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            char c; cin >> c;

            if (c == '#')
                pos[j].push_back(i);
            else
                ++ccnt;
        }
    }

    for (int i = 0; i < m; ++i) {
        vector<int> &v = pos[i];

        for (int j = 0; j < v.size(); ++j) {
            if (j > 0) {
                add(v[j - 1] * m + i, v[j] * m + i);
                if (v[j - 1] == v[j] - 1)
                    add(v[j] * m + i, v[j - 1] * m + i);
            }

            if (i > 0) {
                auto it = lower_bound(pos[i - 1].begin(), pos[i - 1].end(), v[j]);
                if (it != pos[i - 1].end())
                    add(v[j] * m + i, (*it) * m + i - 1);
            }
            if (i < m - 1) {
                auto it = lower_bound(pos[i + 1].begin(), pos[i + 1].end(), v[j]);
                if (it != pos[i + 1].end())
                    add(v[j] * m + i, (*it) * m + i + 1);
            }
        }
    }

    for (int i = 0; i < n * m; ++i)
        if (!vis[i])
            dfs(i);
    for (int i = n * m - 1; ~i; --i)
        if (!scc[topo[i]])
            ++scnt, dfs2(topo[i]);

    for (int i = 0; i < n * m; ++i)
        for (int j : adj[i])
            if (scc[j] != scc[i])
                ++in[scc[j]];

    for (int i = 1; i <= scnt; ++i)
        ans += !in[i];

    cout << ans - ccnt << '\n';
}
