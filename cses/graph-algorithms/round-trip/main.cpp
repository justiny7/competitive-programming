#include <bits/stdc++.h>
#define pb push_back
using namespace std;

int n, m, p[100001];
vector<int> adj[100001], ans;
bool vis[100001];

void dfs(int cur, int par) {
    p[cur] = par;
    vis[cur] = 1;
    for (int u : adj[cur]) {
        if (u == par)
            continue;
        if (!vis[u])
            dfs(u, cur);
        else {
            while (cur != u) {
                ans.push_back(cur);
                cur = p[cur];
            }
            ans.push_back(u);
            cout << ans.size() + 1 << '\n';
            cout << u;
            for (int a : ans)
                cout << " " << a;
            cout << '\n';
            exit(0);
        }
    }
}

int main(void) {
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    for (int i = 1; i <= n; ++i)
        if (!vis[i])
            dfs(i, -1);
    cout << "IMPOSSIBLE\n";
}
