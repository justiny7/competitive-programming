#include <bits/stdc++.h>
using namespace std;
using ll=long long;

const int mxN=5e3+1;
const ll M=1e9+7;
int n, k, q;
ll dp[mxN][mxN], cnt[mxN][mxN], c[mxN], a[mxN], ret;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> k >> q;
    for (int i=0; i<n; ++i)
        cin >> a[i];
    for (int i=0; i<n; ++i)
        dp[0][i]=1;
    for (int i=1; i<=k; ++i) {
        for (int j=0; j<n; ++j) {
            if (j>0)
                (dp[i][j]+=dp[i-1][j-1])%=M;
            if (j<n-1)
                (dp[i][j]+=dp[i-1][j+1])%=M;
        }
    }
    for (int i=0; i<=k; ++i)
        for (int j=0; j<n; ++j)
            cnt[i][j]=(dp[i][j]*dp[k-i][j])%M;
    for (int i=0; i<=k; ++i)
        for (int j=0; j<n; ++j)
            (c[j]+=cnt[i][j])%=M;
    for (int i=0; i<n; ++i)
        (ret+=(c[i]*a[i])%M)%=M;
    while (q--) {
        int i; ll x;
        cin >> i >> x, --i;
        (ret+=c[i]*(x-a[i]+M)%M)%=M;
        cout << ret << '\n';
        a[i]=x;
    }
}

