#include <bits/stdc++.h>
using namespace std;
using ll=long long;

const int mxN=5e3+1, mxV=4e6+1;
int n, q, a[mxN], cnt[mxV];
ll dp[mxN][mxN]; //dp[i][j] = # of 3sums with lb = i and ub = j, then do transitions

int main() {
    ifstream cin("threesum.in");
    ofstream cout("threesum.out");
    cin >> n >> q;
    for (int i=1; i<=n; ++i)
        cin >> a[i], a[i]+=1e6;
    for (int i=1; i<=n; ++i) {
        for (int j=i+1; j<=n; ++j) {
            dp[i][j]+=cnt[(int)3e6-a[j]-a[i]];
            ++cnt[a[j]];
        }
        for (int j=i+1; j<=n; ++j)
            --cnt[a[j]];
    }
    for (int i=n; i; --i)
        for (int j=i+1; j<=n; ++j)
            dp[i][j]+=dp[i+1][j]+dp[i][j-1]-dp[i+1][j-1];
    while (q--) {
        int l, r;
        cin >> l >> r;
        cout << dp[l][r] << '\n';
    }
}

