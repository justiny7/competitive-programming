#include <bits/stdc++.h>
using namespace std;
using ll=long long;

const int mxN=51, mxW=2.5e3+1;
int n, A, a[mxN];
ll dp[mxW][mxN];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> A;
    for (int i=0; i<n; ++i)
        cin >> a[i];
    dp[0][0]=1;
    for (int i=0; i<n; ++i)
        for (int j=mxW; ~j; --j)
            for (int k=n-1; ~k; --k)
                if (j+a[i]<mxW)
                    dp[j+a[i]][k+1]+=dp[j][k];
    ll ans=0;
    for (int i=A; i/A<=n; i+=A)
        ans+=dp[i][i/A];
    cout << ans << '\n';
}

