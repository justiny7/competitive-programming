#include <bits/stdc++.h>
using namespace std;
using ll=long long;

const int mxN=101, mxSum=1e5+1;
ll n, W, w[mxN], v[mxN], dp[mxSum];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> W;
    for (int i=0; i<n; ++i)
        cin >> w[i] >> v[i];
    memset(dp, 0x3f, sizeof(dp));
    dp[0]=0;
    for (int i=0; i<n; ++i)
        for (int j=mxSum-1; j>=0; --j)
            if (j-v[i]>=0)
                dp[j]=min(dp[j], dp[j-v[i]]+w[i]);
    for (int i=mxSum-1; i>=0; --i)
        if (dp[i]<=W) {
            cout << i << '\n';
            break;
        }
}
