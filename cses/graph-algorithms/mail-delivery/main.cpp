//Eulerian Cycle
#include <bits/stdc++.h>
using namespace std;

const int mxN=1e5+1;
int n, m, c;
set<int> adj[mxN];
vector<int> cycle;
bool vis[mxN];

void go(int v=1) {
    while (!adj[v].empty()) {
        int u=*adj[v].begin();
        adj[v].erase(u);
        adj[u].erase(v);
        go(u);
    }
    cycle.push_back(v);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    while (m--) {
        int a, b;
        cin >> a >> b;
        adj[a].insert(b);
        adj[b].insert(a);
    }
    for (int i=1; i<=n; ++i)
        if (adj[i].size()&1) {
            cout << "IMPOSSIBLE\n";
            return 0;
        }
    go();
    for (int i=1; i<=n; ++i)
        if (!adj[i].empty()) {
            cout << "IMPOSSIBLE\n";
            return 0;
        }
    for (int i=0; i<cycle.size(); ++i) {
        if (i)
            cout << " ";
        cout << cycle[i];
    }
    cout << '\n';
}
