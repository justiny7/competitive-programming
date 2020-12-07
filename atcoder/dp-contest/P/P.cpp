#include <bits/stdc++.h>
using namespace std;
using ll=long long;

const int mxN=1e5+1;
const ll M=1e9+7;
int n;
ll dp[mxN][2];
vector<int> adj[mxN];

ll dfs(int v, bool c, int p=0) {
    if (~dp[v][c])
        return dp[v][c];
    ll cur=1;
    for (int u:adj[v]) {
        if (u==p)
            continue;
        if (c)
            cur=(cur*dfs(u, 0, v))%M;
        else
            cur=(cur*((dfs(u, 0, v)+dfs(u, 1, v))%M)%M);
    }
    return dp[v][c]=cur;
}

int main() {
    memset(dp, -1, sizeof(dp));
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for (int i=1; i<n; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    cout << (dfs(1, 0)+dfs(1, 1))%M << '\n';
}

