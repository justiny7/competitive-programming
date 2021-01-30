//Yay worked first try
#include <bits/stdc++.h>
using namespace std;
using ll=long long;

const int mxN=2e3+1;
int n;
ll l, w[mxN], h[mxN], dp[mxN]; //dp[i] = min height ending at i

int main() {
    memset(dp, 0x3f, sizeof(dp));
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> l;
    for (int i=1; i<=n; ++i) {
        cin >> h[i] >> w[i];
        w[i]+=w[i-1];
    }
    dp[0]=0;
    for (int i=1; i<=n; ++i) {
        ll mx=h[i];
        for (int j=i-1; ~j; --j) {
            if (w[i]-w[j]>l)
                break;
            dp[i]=min(dp[i], dp[j]+mx);
            mx=max(mx, h[j]);
        }
    }
    cout << dp[n] << '\n';
}

