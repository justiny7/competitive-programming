#include <bits/stdc++.h>
using namespace std;
using db=double;

const int mxN=1e5+1;
int n;
db ans;
vector<int> adj[mxN];

void dfs(int v=1, int p=0, int l=0, db cur=1.0) {
    if ((v^1) && adj[v].size()==1)
        ans+=cur*l;
    for (int u:adj[v])
        if (u^p)
            dfs(u, v, l+1, cur/db(adj[v].size()-db(v==1?0:1)));
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for (int i=1; i<n; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs();
    cout << setprecision(12) << fixed << ans << '\n';
}

