#include <bits/stdc++.h>
#define pb push_back
using namespace std;
using ll=long long;

const int mxN=21;
const ll M=1e9+7;
ll n, m, dp[1<<mxN][mxN];
vector<int> adj[mxN];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    while (m--) {
        int a, b;
        cin >> a >> b;
        adj[a-1].pb(b-1);
    }
    dp[1][0]=1;
    for (int i=1; i<(1<<n); i+=2) {
        if ((i^((1<<n)-1) && i&(1<<(n-1))) || __builtin_popcount(i)<2)
            continue;
        for (int j=0; j<n; ++j)
            if (i&(1<<j))
                for (int k:adj[j])
                    dp[i][k]=(dp[i][k]+dp[i^(1<<k)][j])%M;
    }
    cout << dp[(1<<n)-1][n-1] << '\n';
}

