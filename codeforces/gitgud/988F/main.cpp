#include <bits/stdc++.h>
using namespace std;

const int mxN=2e3+10;
int a, n, m, u[mxN], w[mxN], dp[mxN][mxN];
bool rain[mxN];

int main() {
    memset(dp, -1, sizeof(dp));
    memset(u, -1, sizeof(u));
    cin.tie(0)->sync_with_stdio(0);
    cin >> a >> n >> m, ++a;
    for (int i=0; i<n; ++i) {
        int l, r;
        cin >> l >> r, ++l, ++r;
        for (int j=l; j<r; ++j)
            rain[j]=1;
    }
    for (int i=1; i<=m; ++i) {
        int x, p;
        cin >> x >> p, ++x;
        if (u[x]<0 || p<w[u[x]])
            u[x]=i, w[i]=p;
    }
    dp[0][0]=0;
    for (int t=1; t<=a; ++t) {
        if (~u[t]) {
            int mn=INT_MAX;
            for (int i=rain[t-1]; i<=m; ++i)
                if (~dp[t-1][i])
                    mn=min(mn, dp[t-1][i]);
            if (mn^INT_MAX)
                dp[t][u[t]]=mn+w[u[t]];
        }
        if (!rain[t]) {
            int mn=INT_MAX;
            for (int i=0; i<=m; ++i)
                if (~dp[t-1][i])
                    mn=min(mn, dp[t-1][i]);
            if (mn^INT_MAX)
                dp[t][0]=mn;
        }
        for (int i=1; i<=m; ++i)
            if (~dp[t-1][i])
                dp[t][i]=dp[t-1][i]+w[i];
    }
    int ans=INT_MAX;
    for (int i=0; i<=m; ++i)
        if (~dp[a][i])
            ans=min(ans, dp[a][i]);
    cout << (ans^INT_MAX?ans:-1) << '\n';
}

