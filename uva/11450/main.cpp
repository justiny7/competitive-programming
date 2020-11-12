#include <bits/stdc++.h>
using namespace std;

const int mxC=201, mxN=21;
int n, m, k, dp[mxN][mxC];

int main() {
    int t; scanf("%d", &t);
    while (t--) {
        memset(dp, 0, sizeof(dp));
        scanf("%d %d", &n, &m);
        vector<vector<int>> a(m+1);
        for (int i=1; i<=m; ++i) {
            scanf("%d", &k);
            a[i].resize(k);
            for (int &j:a[i])
                scanf("%d", &j);
        }
        dp[0][0]=1;
        for (int i=1; i<=m; ++i)
            for (int j=0; j<a[i].size(); ++j)
                for (int l=0; l<mxC; ++l)
                    if (dp[i-1][l] && l+a[i][j]<mxC)
                        dp[i][l+a[i][j]]=1;
        int ans=-1;
        for (int i=1; i<=n; ++i)
            if (dp[m][i])
                ans=i;
        if (~ans)
            printf("%d\n", ans);
        else
            printf("no solution\n");
    }
}

