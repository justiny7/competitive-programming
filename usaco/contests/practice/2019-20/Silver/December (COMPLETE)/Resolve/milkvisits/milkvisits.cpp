#include <bits/stdc++.h>
#define pb push_back
using namespace std;

const int mxN=1e5+1;
int n, m, comp[mxN], cur;
string type;
vector<int> adj[mxN];
bool vis[mxN];

void dfs(int v) {
    comp[v]=cur, vis[v]=1;
    for (int u:adj[v])
        if (!vis[u] && type[u-1]==type[v-1])
            dfs(u);
}

int main() {
    ifstream cin("milkvisits.in");
    ofstream cout("milkvisits.out");
    cin >> n >> m >> type;
    for (int i=1; i<n; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    for (int i=1; i<=n; ++i)
        if (!comp[i])
            ++cur, dfs(i);
    while (m--) {
        int a, b; char c;
        cin >> a >> b >> c;
        if (type[a-1]^type[b-1])
            cout << 1;
        else if (type[a-1]==c || type[b-1]==c)
            cout << 1;
        else
            cout << (comp[a]==comp[b]?0:1);
    }
    cout << '\n';
}

