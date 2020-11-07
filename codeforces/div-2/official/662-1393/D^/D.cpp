#include <bits/stdc++.h>
using namespace std;

const int mxN=2e3+1;
int n, m, dp[mxN][mxN], ans[mxN][mxN], tot;
char a[mxN][mxN];

void print() {
    cout << '\n';
    for (int i=1; i<=n; ++i) {
        for (int j=1; j<=m; ++j)
            cout << a[i][j];
        cout << '\n';
    }
}

int main() {
    memset(ans, 0x3f, sizeof(ans));
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    for (int i=1; i<=n; ++i)
        for (int j=1; j<=m; ++j)
            cin >> a[i][j];
    for (int t=0; t<4; ++t) {
        memset(dp, 0, sizeof(dp));
        for (int i=1; i<=n; ++i) {
            for (int j=1; j<=m; ++j) {
                if (a[i][j]!=a[i-1][j] || a[i][j]!=a[i][j-1])
                    dp[i][j]=1;
                else
                    dp[i][j]=min(dp[i-1][j], dp[i][j-1])+1;
                ans[i][j]=min(ans[i][j], dp[i][j]);
            }
        }
        if (t&1)
            for (int i=1; i<=n; ++i)
                for (int j=1;j<=m/2; ++j) {
                    swap(a[i][j], a[i][m-j+1]);
                    swap(ans[i][j], ans[i][m-j+1]);
                }
        else
            for (int i=1; i<=m; ++i)
                for (int j=1; j<=n/2; ++j) {
                    swap(a[j][i], a[n-j+1][i]);
                    swap(ans[j][i], ans[n-j+1][i]);
                }
        //print();
    }
    for (int i=1; i<=n; ++i)
        for (int j=1; j<=m; ++j)
            tot+=ans[i][j];
    cout << tot << '\n';
}

