#include <bits/stdc++.h>
#define pb push_back
using namespace std;
using ll=long long;

const int mxN=1e5+1, mxX=11;
const ll M=1e9+7;
int n, m, k, x;
vector<int> adj[mxN];
ll ans=0, dp[mxN][mxX][3]; //0: 1 - k-1, 1: k, 2: k+1 - m

ll add(ll a, ll b) {
    return ((a+b)%M);
}
ll mult(ll a, ll b) {
    return ((a*b)%M);
}

void dfs(int v=1, int p=0) {
    dp[v][0][0]=k-1, dp[v][0][2]=m-k, dp[v][1][1]=1;
    for (int u:adj[v])
        if (u^p) {
            dfs(u, v);
            ll dp2[mxX][3]={};
            for (int i=0; i<=x; ++i)
                for (int j=0; i+j<=x; ++j) {
                    dp2[i+j][0]=add(dp2[i+j][0], mult(dp[v][i][0], dp[u][j][0]));
                    dp2[i+j][0]=add(dp2[i+j][0], mult(dp[v][i][0], dp[u][j][1]));
                    dp2[i+j][0]=add(dp2[i+j][0], mult(dp[v][i][0], dp[u][j][2]));
                    dp2[i+j][2]=add(dp2[i+j][2], mult(dp[v][i][2], dp[u][j][0]));
                    dp2[i+j][2]=add(dp2[i+j][2], mult(dp[v][i][2], dp[u][j][2]));
                    dp2[i+j][1]=add(dp2[i+j][1], mult(dp[v][i][1], dp[u][j][0]));
                }
            for (int i=0; i<=x; ++i)
                for (int j=0; j<3; ++j)
                    dp[v][i][j]=dp2[i][j];
        }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    for (int i=1; i<n; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    cin >> k >> x;
    dfs();
    for (int i=0; i<=x; ++i)
        for (int j=0; j<3; ++j)
            ans=add(ans, dp[1][i][j]);
    cout << ans << '\n';
}

