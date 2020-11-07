//Binary search on answer
//Yay worked first try
#include <bits/stdc++.h>
using namespace std;
using ll=long long;

const int mxN=251, mxW=1e3+1;
const ll NINF=-0x3f3f3f3f3f3f3f3f;
ll n, W, w[mxN], t[mxN], dp[mxW];

bool works(ll x) {
    memset(dp, -0x3f, sizeof(dp));
    dp[0]=0;
    for (int i=0; i<n; ++i)
        for (int j=W; j>=0; --j)
            if (dp[j]!=NINF)
                dp[min(W, j+w[i])]=max(dp[min(W, j+w[i])], dp[j]+t[i]*1000-w[i]*x);
    return (dp[W]>=0);
}

int main() {
    ifstream cin("talent.in");
    ofstream cout("talent.out");
    cin >> n >> W;
    for (int i=0; i<n; ++i)
        cin >> w[i] >> t[i];
    ll lo=0, hi=mxN*mxN*mxW;
    while (lo<hi) {
        ll mid=(lo+hi+1)/2;
        if (works(mid))
            lo=mid;
        else
            hi=mid-1;
    }
    cout << lo << '\n';
}

