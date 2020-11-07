//Yay worked first try
#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
using ll=long long;
using pll=pair<ll, ll>;

const int mxN=1e5+1;
ll n, m, ans=LLONG_MAX;
pll a[mxN], t[mxN<<2];

pll merge(pll a, pll b) {
    return pll(a.fi+b.fi, max(a.se, b.se));
}
void build(int v=1, int l=0, int r=n-1) {
    if (l==r) {
        t[v]=a[l];
        return;
    }
    int m=l+r>>1;
    build(v<<1, l, m);
    build(v<<1|1, m+1, r);
    t[v]=merge(t[v<<1], t[v<<1|1]);
}
pll query(int l, int r, int lo=0, int hi=n-1, int v=1) {
    if (l>hi || r<lo)
        return pll(0, 0);
    if (lo>=l && hi<=r)
        return t[v];
    int m=lo+hi>>1;
    return merge(query(l, r, lo, m, v<<1), query(l, r, m+1, hi, v<<1|1));
}

int main() {
    ifstream cin("hayfeast.in");
    ofstream cout("hayfeast.out");
    cin >> n >> m;
    for (int i=0; i<n; ++i)
        cin >> a[i].fi >> a[i].se;
    build();
    for (int i=0, j=0; i<n; ++i) {
        while (j<n && query(i, j).fi<m)
            ++j;
        if (j<n && query(i, j).fi>=m)
            ans=min(ans, query(i, j).se);
    }
    cout << ans << '\n';
}

