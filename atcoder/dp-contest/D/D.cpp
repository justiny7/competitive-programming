#include <bits/stdc++.h>
using namespace std;
using ll=long long;

const int mxN=101, mxW=1e5+1;
ll n, W, v[mxN], w[mxN], dp[mxW];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> W;
    for (int i=0; i<n; ++i)
        cin >> w[i] >> v[i];
    for (int j=0; j<n; ++j)
        for (int i=W; i>=0; --i)
            if (i-w[j]>=0)
                dp[i]=max(dp[i], dp[i-w[j]]+v[j]);
    cout << dp[W] << '\n';
}
