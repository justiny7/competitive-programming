#include <bits/stdc++.h>
using namespace std;
using ll=long long;

const int mxN=20;
int n, x, dp[1<<mxN], dp2[1<<mxN];
ll w[mxN];

int main() {
    memset(dp, 0x3f, sizeof(dp));
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> x;
    for (int i=0; i<n; ++i)
        cin >> w[i];
    dp[0]=1;
    for (int i=1; i<(1<<n); ++i) {
        for (int j=0; j<n; ++j) {
            if (i&(1<<j)) {
                int k=(i^(1<<j)), cnt=dp[k], cur=dp2[k];
                if (cur+w[j]<=x)
                    cur+=w[j];
                else
                    ++cnt, cur=w[j];
                if (make_pair(cnt, cur)<make_pair(dp[i], dp2[i]))
                    dp[i]=cnt, dp2[i]=cur;
            }
        }
    }
    cout << dp[(1<<n)-1] << '\n';
}
