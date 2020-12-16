//Yay worked first try!
#include <bits/stdc++.h>
using namespace std;

const int mxN=1e5+1, mxM=26;
int n, m, k, ans=INT_MAX, d[mxM][mxM], pref[mxN][mxM], dp[mxN][mxM];
string s;

int main() {
    ifstream cin("cowmbat.in");
    ofstream cout("cowmbat.out");
    cin >> n >> m >> k >> s;
    for (int i=0; i<m; ++i)
        for (int j=0; j<m; ++j)
            cin >> d[i][j];
    for (int k=0; k<m; ++k)
        for (int i=0; i<m; ++i)
            for (int j=0; j<m; ++j)
                d[i][j]=min(d[i][j], d[i][k]+d[k][j]);
    for (int i=1; i<=n; ++i)
        for (int j=0; j<m; ++j)
            pref[i][j]=d[s[i-1]-'a'][j]+pref[i-1][j];
    for (int i=1; i<=n; ++i)
        for (int j=0; j<m; ++j) {
            dp[i][j]=dp[i-1][j]+d[s[i-1]-'a'][j];
            if (i>=k*2) {
                int mn=INT_MAX;
                for (int l=0; l<m; ++l)
                    mn=min(mn, dp[i-k][l]);
                dp[i][j]=min(dp[i][j], mn+pref[i][j]-pref[i-k][j]);
            }
            if (i==n)
                ans=min(ans, dp[i][j]);
        }
    cout << ans << '\n';
}

