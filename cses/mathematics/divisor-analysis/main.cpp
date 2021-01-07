#include <bits/stdc++.h>
using namespace std;
using ll=long long;

const int mxN=1e5+5;
const ll M=1e9+7;
int n;
ll num=1, sum=1, prod=1, a[mxN], b[mxN], pre[mxN], suf[mxN];

ll binpow(ll a, ll b) {
    ll ret=1;
    while (b) {
        if (b&1)
            (ret*=a)%=M;
        (a*=a)%=M, b>>=1;
    }
    return ret;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for (int i=1; i<=n; ++i) {
        ll x, k;
        cin >> x >> k;
        (num*=(k+1))%=M;
        (sum*=(binpow(x, k+1)+M-1)*binpow(x-1, M-2)%M)%=M;
        a[i]=x;
        pre[i]=suf[i]=k+1;
        b[i]=k;
    }
    pre[0]=suf[0]=pre[n+1]=suf[n+1]=1;
    for (int i=1; i<=n; ++i) {
        (pre[i]*=pre[i-1])%=(M-1);
        (suf[n-i+1]*=suf[n-i+2])%=(M-1);
    }
    for (int i=1; i<=n; ++i)
        (prod*=binpow(binpow(a[i], (b[i]*(b[i]+1)/2)), (pre[i-1]*suf[i+1])%(M-1)))%=M;
    cout << num << " " << sum << " " << prod << '\n';
}

