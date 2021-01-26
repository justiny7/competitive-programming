#include <bits/stdc++.h>
using namespace std;
using ll=long long;

const int mxN=2e3+1;
int n, m, q;
ll c[mxN], dp[mxN][mxN], INF=0x7f7f7f7f7f7f7f7f;

int main() {
    memset(dp, 0x7f, sizeof(dp));
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    for (int i=1; i<=m; ++i)
        cin >> c[i];
    dp[1][1]=0;
    for (ll i=1; i<=n; ++i)
        for (ll j=1; j<=m; ++j) {
            if (i==1 && j==1)
                continue;
            dp[i][j]=min(dp[i][j-1]+i*i, dp[i-1][j]+c[j]);
        }
    cin >> q;
    while (q--) {
        int a, b;
        cin >> a >> b;
        cout << dp[a][b] << '\n';
    }
}

