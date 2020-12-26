#include <bits/stdc++.h>
using namespace std;

const int mxN=1e3+1;
int n, m, c, ans, a[mxN], dp[mxN][mxN];
vector<int> adj[mxN];

int main() {
    memset(dp, -1, sizeof(dp));
    ifstream cin("time.in");
    ofstream cout("time.out");
    cin >> n >> m >> c;
    for (int i=1; i<=n; ++i)
        cin >> a[i];
    while (m--) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
    }
    dp[0][1]=0;
    for (int t=0; t<mxN; ++t) {
        for (int v=1; v<=n; ++v)
            if (~dp[t][v]) {
                if (v==1)
                    ans=max(ans, dp[t][v]-c*t*t);
                if (t+1<mxN)
                    for (int u:adj[v])
                        dp[t+1][u]=max(dp[t+1][u], dp[t][v]+a[u]);
            }
    }
    cout << ans << '\n';
}

