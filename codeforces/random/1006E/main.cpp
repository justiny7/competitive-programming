#include <bits/stdc++.h>
using namespace std;

const int mxN=2e5+1;
int n, q, t, pos[mxN], ord[mxN], lst[mxN];
set<int> adj[mxN];

void dfs(int v=1) {
    t++;
    pos[v]=t, ord[t]=v;
    for (int u:adj[v])
        dfs(u);
    lst[v]=ord[t];
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> q;
    for (int i=2; i<=n; ++i) {
        int a; cin >> a;
        adj[a].insert(i);
    }
    dfs();
    while (q--) {
        int v, k;
        cin >> v >> k;
        if (pos[lst[v]]-pos[v]+1<k)
            cout << "-1\n";
        else
            cout << ord[pos[v]+k-1] << '\n';
    }
}

