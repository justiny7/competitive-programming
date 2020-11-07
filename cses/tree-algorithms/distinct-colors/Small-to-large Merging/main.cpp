#include <bits/stdc++.h>
#define pb push_back
using namespace std;

const int mxN=2e5+1;
int n, c[mxN], ans[mxN];
vector<int> adj[mxN];

set<int> dfs(int v=1, int p=0) {
    set<int> cur={c[v]};
    for (int u:adj[v])
        if (u^p) {
            set<int> s=dfs(u, v);
            if (s.size()>cur.size())
                cur.swap(s);
            for (int i:s)
                cur.insert(i);
        }
    ans[v]=cur.size();
    return cur;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for (int i=1; i<=n; ++i)
        cin >> c[i];
    for (int i=1; i<n; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    dfs();
    for (int i=1; i<=n; ++i)
        cout << ans[i] << " \n"[i==n];
}

