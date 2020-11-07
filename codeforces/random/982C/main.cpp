#include <bits/stdc++.h>
#define pb push_back
using namespace std;

const int mxN=1e5+1;
int n, ans;
vector<int> adj[mxN];

int dfs(int v=1, int p=0) {
    int cnt=1;
    for (int u:adj[v])
        if (u^p)
            cnt+=dfs(u, v);
    if (cnt%2==0)
        ++ans;
    return cnt;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    if (n&1)
        return cout << "-1\n", 0;
    for (int i=1; i<n; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    dfs();
    cout << ans-1 << '\n';
}


