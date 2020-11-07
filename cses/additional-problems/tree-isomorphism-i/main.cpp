#include <bits/stdc++.h>
#define pb push_back
using namespace std;

const int mxN=1e5+1;
int n, id;
vector<int> adj[2][mxN];
map<vector<int>, int> mp;

int dfs(int t, int v=1, int p=0) {
    vector<int> cur;
    for (int u:adj[t][v])
        if (u^p)
            cur.pb(dfs(t, u, v));
    sort(cur.begin(), cur.end());
    return (mp.count(cur)?mp[cur]:mp[cur]=id++);
}

void solve() {
    mp.clear(), id=0;
    cin >> n;
    for (int i=1; i<=n; ++i)
        adj[0][i].clear(), adj[1][i].clear();
    for (int t=0; t<2; ++t)
        for (int i=1; i<n; ++i) {
            int a, b;
            cin >> a >> b;
            adj[t][a].pb(b);
            adj[t][b].pb(a);
        }
    cout << (dfs(0)^dfs(1)?"NO\n":"YES\n");
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--)
        solve();
}

