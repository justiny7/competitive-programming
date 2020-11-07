#include <bits/stdc++.h>
using namespace std;

const int mxN=1e3+1, M=1e9+7;
int h, w, dp[mxN][mxN];
bool ok[mxN][mxN];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> h >> w;
    for (int i=1; i<=h; ++i)
        for (int j=1; j<=w; ++j) {
            char c; cin >> c;
            ok[i][j]=(c=='.');
        }
    if (ok[1][1])
        dp[1][1]=1;
    for (int i=1; i<=h; ++i)
        for (int j=1; j<=w; ++j)
            if (ok[i][j] && !(i==1 && j==1))
                dp[i][j]=(dp[i-1][j]+dp[i][j-1])%M;
    cout << dp[h][w] << '\n';
}
