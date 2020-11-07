#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
using ll=long long;
using pii=pair<int, int>;

const int mxN=3e5+1;
const ll M=998244353;
ll fact[mxN];
int n;
pii a[mxN];
map<ll, int> mp1, mp2;
map<pii, int> mp3;

int main() {
    fact[1]=1;
    for (int i=2; i<mxN; ++i)
        fact[i]=fact[i-1]*i%M;
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for (int i=0; i<n; ++i) {
        cin >> a[i].fi >> a[i].se;
        ++mp1[a[i].fi], ++mp2[a[i].se], ++mp3[a[i]];
    }
    sort(a, a+n);
    bool f=1;
    for (int i=1; i<n; ++i)
        if (a[i].se<a[i-1].se)
            f=0;
    ll x=1, y=1, z=0, tot=1;
    for (int i=1; i<=n; ++i)
        tot=tot*i%M;
    for (auto p:mp1)
        x=x*fact[p.se]%M;
    for (auto p:mp2)
        y=y*fact[p.se]%M;
    if (f) {
        z=1;
        for (auto p:mp3)
            z=z*fact[p.se]%M;
    }
    //cout << tot << " " << x << " " << y << " " << z << '\n';
    cout << (tot-x+M-y+M+z+M)%M << '\n';
}


