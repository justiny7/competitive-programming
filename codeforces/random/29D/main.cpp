#include <bits/stdc++.h>
using namespace std;

const int N = 301;
int n, sz, ptr;
vector<int> adj[N], ord, ans;
set<int> c[N], leaves;
bool vis[N];

void dfs(int v = 1, int p = 0) {
    c[v].insert(v);
    for (int u : adj[v]) {
        if (u != p) {
            dfs(u, v);
            for (int k : c[u])
                c[v].insert(k);
        }
    }
}
void dfs2(int v = 1) {
    ans.push_back(v);
    if (v == ord[ptr]) {
        ++ptr;
        return;
    }
    while (ptr < sz) {
        bool f = 0;
        for (int u : adj[v]) {
            if (vis[u] || !c[u].count(ord[ptr]))
                continue;
            vis[u] = f = 1;
            dfs2(u);
            ans.push_back(v);
            break;
        }
        if (!f)
            break;
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for (int i = 1, u, v; i < n; ++i) {
        cin >> u >> v;
        adj[v].push_back(u);
        adj[u].push_back(v);
    }
    dfs();
    for (int i = 1; i <= n; ++i)
        sz += (c[i].size() == 1);
    ord.resize(sz);
    for (int &v : ord)
        cin >> v;
    vis[1] = 1;
    dfs2();
    if (ptr < sz)
        cout << "-1\n";
    else {
        assert(ans.size() == n * 2 - 1);
        for (int i = 0; i < ans.size(); ++i)
            cout << ans[i] << " \n"[i == ans.size() - 1];
    }
}
