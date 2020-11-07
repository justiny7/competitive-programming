//Binary lifting
#include <bits/stdc++.h>
using namespace std;

const int mxN=2e5+1, mxL=31;
int n, q, dp[mxN][mxL];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> q;
    for (int i=1; i<=n; ++i)
        cin >> dp[i][0];
    for (int j=1; j<mxL; ++j)
        for (int i=1; i<=n; ++i)
            dp[i][j]=dp[dp[i][j-1]][j-1];
    while (q--) {
        int v, k, cur;
        cin >> v >> k;
        while (k)
            cur=log2(k), v=dp[v][cur], k-=exp2(cur);
        cout << v << '\n';
    }
}
