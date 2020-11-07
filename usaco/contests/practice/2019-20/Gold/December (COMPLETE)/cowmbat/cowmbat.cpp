//Got up to Floyd-Warshall and prefix sums before getting a hint for dpmin array from solution
#include <bits/stdc++.h>
using namespace std;

const int mxN=1e5+1, mxM=26;
int n, m, k, seq[mxN], c[mxM][mxM], pref[mxN][mxM], dp[mxN][mxM], ans[mxN];
string s;

int main() {
    ifstream cin("cowmbat.in");
    ofstream cout("cowmbat.out");
    memset(dp, 0x3f, sizeof(dp));
    memset(ans, 0x3f, sizeof(ans));
    cin >> n >> m >> k >> s;
    for (int i=1; i<=n; ++i)
        seq[i]=s[i-1]-'a';
    for (int i=0; i<m; ++i)
        for (int j=0; j<m; ++j)
            cin >> c[i][j];
    for (int k=0; k<m; ++k)
        for (int i=0; i<m; ++i)
            for (int j=0; j<m; ++j)
                c[i][j]=min(c[i][j], c[i][k]+c[k][j]);
    for (int i=1; i<=n; ++i)
        for (int j=0; j<m; ++j)
            pref[i][j]=c[seq[i]][j]+pref[i-1][j];
    ans[0]=0;
    for (int i=1; i<=n; ++i)
        for (int j=0; j<m; ++j) {
            dp[i][j]=min(dp[i][j], dp[i-1][j]+c[seq[i]][j]);
            if (i>=k)
                dp[i][j]=min(dp[i][j], pref[i][j]-pref[i-k][j]+ans[i-k]);
            ans[i]=min(ans[i], dp[i][j]);
        }
    cout << ans[n] << '\n';
}

