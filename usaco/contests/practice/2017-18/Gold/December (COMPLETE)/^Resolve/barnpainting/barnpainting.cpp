//Yay worked first try
#include <bits/stdc++.h>
#define pb push_back
using namespace std;
using ll=long long;

const int mxN=1e5+1;
const ll M=1e9+7;
int n, k, col[mxN];
ll dp[mxN][3];
vector<int> adj[mxN];

ll dfs(int v, int c, int p=0) {
    if (~dp[v][c])
        return dp[v][c];
    ll cur=1;
    for (int u:adj[v]) {
        if (u==p)
            continue;
        ll cur2=0;
        if (~col[u]) {
            if (c==col[u])
                return 0;
            cur2=(cur2+dfs(u, col[u], v))%M;
        }
        else
            for (int i=0; i<3; ++i)
                if (i^c)
                    cur2=(cur2+dfs(u, i, v))%M;
        cur=(cur*cur2)%M;
    }
    return dp[v][c]=cur;
}

int main() {
    memset(dp, -1, sizeof(dp));
    memset(col, -1, sizeof(col));
    ifstream cin("barnpainting.in");
    ofstream cout("barnpainting.out");
    cin >> n >> k;
    for (int i=1; i<n; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    while (k--) {
        int a, b;
        cin >> a >> b;
        col[a]=b-1;
    }
    if (~col[1])
        cout << dfs(1, col[1]) << '\n';
    else {
        ll ans=0;
        for (int i=0; i<3; ++i)
            ans=(ans+dfs(1, i))%M;
        cout << ans << '\n';
    }
}

