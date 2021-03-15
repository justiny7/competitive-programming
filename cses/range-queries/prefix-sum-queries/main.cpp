#include <bits/stdc++.h>
using namespace std;
using ll=long long;

const int mxN=2e5+1;
int n, q;
ll a[mxN], b[mxN], t[mxN<<2], lz[mxN<<2];

inline void push(int l, int r, int v) {
    if (l^r) {
        lz[v<<1]+=lz[v];
        lz[v<<1|1]+=lz[v];
        t[v<<1]+=lz[v];
        t[v<<1|1]+=lz[v];
    }
    lz[v]=0;
}
void build(int l=0, int r=n-1, int v=1) {
    if (l==r) {
        t[v]=a[l];
        return;
    }
    int m=l+r>>1;
    build(l, m, v<<1);
    build(m+1, r, v<<1|1);
    t[v]=max(t[v<<1], t[v<<1|1]);
}
void upd(int l, int r, ll x, int lo=0, int hi=n-1, int v=1) {
    if (l>hi || r<lo)
        return;
    if (lo>=l && hi<=r) {
        t[v]+=x;
        lz[v]+=x;
        return;
    }
    push(lo, hi, v);
    int m=lo+hi>>1;
    upd(l, r, x, lo, m, v<<1);
    upd(l, r, x, m+1, hi, v<<1|1);
    t[v]=max(t[v<<1], t[v<<1|1]);
}
ll query(int l, int r, int lo=0, int hi=n-1, int v=1) {
    if (l>hi || r<lo)
        return LLONG_MIN;
    if (lo>=l && hi<=r)
        return t[v];
    push(lo, hi, v);
    int m=lo+hi>>1;
    return max(query(l, r, lo, m, v<<1), query(l, r, m+1, hi, v<<1|1));
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> q;
    for (int i=0; i<n; ++i) {
        cin >> a[i], b[i]=a[i];
        if (i)
            a[i]+=a[i-1];
    }
    build();
    while (q--) {
        int t; ll x, y;
        cin >> t >> x >> y;
        if (t&1) {
            upd(x-1, n-1, y-b[x-1]);
            b[x-1]=y;
        }
        else
            cout << max(0LL, query(x-1, y-1)-(x>1?query(x-2, x-2):0)) << '\n';
    }
}

