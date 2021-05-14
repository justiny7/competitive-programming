#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 69;
int n, o, mx, dist[2][N], par[N];
long long tot = 0;
vector<array<int, 3>> ans;
vector<int> adj[N];
set<int> diam;

void dfs(int c, int v, int p = 0, int d = 0) {
    dist[c][v] = d;
    par[v] = p;
    if (dist[c][v] > dist[c][mx])
        mx = v;
    for (int u : adj[v])
        if (u != p)
            dfs(c, u, v, d + 1);
}
void dfs2(int v, int p = 0) {
    if (!diam.count(v)) {
        //cout << "v: " << v << " " << dist[1][v] << " " << dist[0][v] << '\n';
        if (dist[0][v] > dist[1][v]) {
            tot += dist[0][v];
            ans.push_back({v, o, v});
        }
        else {
            tot += dist[1][v];
            ans.push_back({v, mx, v});
        }
    }
    for (int u : adj[v])
        if (u != p)
            dfs2(u, v);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for (int i = 1, u, v; i < n; ++i) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(0, 1);
    dfs(1, mx), o = mx;
    dfs(0, mx);
    diam.insert(mx);
    int cur = par[mx];
    long long c = 1;
    while (cur) {
        tot += c++;
        diam.insert(cur);
        ans.push_back({cur, mx, cur});
        cur = par[cur];
    }
    //cout << "tot: " << tot << '\n';
    //for (int i : diam)
    //cout << i << " ";
    //cout << '\n';
    dfs2(mx);
    cout << tot << '\n';
    for (int i = n - 2; ~i; --i)
        cout << ans[i][0] << " " << ans[i][1] << " " << ans[i][2] << '\n';
}
