#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 1;
int n, mx, d[N], par[N];
vector<int> adj[N];
set<int> s;

void dfs(int v = 1, int p = 0, int dep = 0) {
    par[v] = p, d[v] = dep;
    if (d[v] > d[mx])
        mx = v;
    for (int u : adj[v])
        if (u != p)
            dfs(u, v, dep + 1);
}
void dfs2(int v, int p, int dep = 1) {
    bool f = 0;
    for (int u : adj[v])
        if (u != p)
            dfs2(u, v, dep + 1), f = 1;
    if (!f)
        s.insert(dep);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for (int i = 1, u, v; i < n; ++i) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs();
    dfs(mx);
    int diam = d[mx], k = diam / 2, st = mx;
    vector<int> cands;
    while (k--)
        st = par[st];
    cands.push_back(st);
    if (diam & 1)
        cands.push_back(par[st]);
    int ans = INT_MAX;
    for (int i : cands) {
        set<int> here;
        bool f = 0;
        for (int u : adj[i]) {
            s.clear();
            dfs2(u, i);
            if (s.size() > 1)
                f = 1;
            else
                here.insert(*s.begin());
        }
        if (f || here.size() > 2)
            continue;
        int cur = 0;
        for (int j : here)
            cur += j;
        ans = min(ans, cur);
    }
    if (ans != INT_MAX) {
        while (ans % 2 == 0)
            ans /= 2;
        cout << ans << '\n';
    }
    else
        cout << "-1\n";
}
