#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
using ll=long long;
using pll=pair<ll, ll>;

const int mxN=1e5+1;
ll n, m, a[mxN];
pll seg[mxN*4];

pll merge(pll a, pll b) {
    if (a.fi^b.fi)
        return min(a, b);
    return pll(a.fi, a.se+b.se);
}

void build(int v=1, int l=0, int r=n-1) {
    if (l==r) {
        seg[v]=pll(a[l], 1);
        return;
    }
    int mid=(l+r)/2;
    build(v*2, l, mid);
    build(v*2+1, mid+1, r);
    seg[v]=merge(seg[v*2], seg[v*2+1]);
}

void upd(int i, ll x, int l=0, int r=n-1, int v=1) {
    if (l==r) {
        seg[v]=pll(x, 1);
        return;
    }
    int mid=(l+r)/2;
    if (i<=mid)
        upd(i, x, l, mid, v*2);
    else
        upd(i, x, mid+1, r, v*2+1);
    seg[v]=merge(seg[v*2], seg[v*2+1]);
}

pll query(int l, int r, int lo=0, int hi=n-1, int v=1) {
    if (hi<l || lo>r)
        return pll(INT_MAX, 0);
    if (lo>=l && hi<=r)
        return seg[v];
    int mid=(lo+hi)/2;
    return merge(query(l, r, lo, mid, v*2), query(l, r, mid+1, hi, v*2+1));
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    for (int i=0; i<n; ++i)
        cin >> a[i];
    build();
    while (m--) {
        int a, b, c;
        cin >> a >> b >> c;
        if (a==1)
            upd(b, c);
        else {
            pll q=query(b, c-1);
            cout << q.fi << " " << q.se << '\n';
        }
    }
}

