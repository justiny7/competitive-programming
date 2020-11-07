#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
using namespace std;
using ll=long long;
using pll=pair<ll, ll>;

const ll M=998244353;
const int mxN=1e3+1;
ll n, m, a[mxN], sr, sc;
map<ll, ll> cnt;
vector<pll> vals;

ll binpow(ll a, ll b) {
    ll ans=1;
    while (b) {
        if (b&1)
            ans=ans*a%M;
        a=a*a%M, b>>=1;
    }
    return ans;
}

ll modinv(ll x) {
    return binpow(x, M-2);
}

inline ll dist(ll x1, ll y1, ll x2, ll y2) {
    return (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    for (int i=0; i<n; ++i)
        for (int j=0; j<m; ++j)
            cin >> a[i][j], ++cnt[a[i][i]];
    for (auto& p:cnt)
        vals.pb();
    sort(vals.begin(), vals.end());
    cin >> sr >> sc;
}


