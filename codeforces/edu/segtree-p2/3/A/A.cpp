#include <bits/stdc++.h>
using namespace std;
using ll=long long;

const int mxN=1e5+1;
const ll B=1e10;
ll n, q, lz[mxN<<2];
struct node {
    ll sum, pref, suf, ans;
} t[mxN<<2];

inline node merge(node& a, node& b) {
    node c;
    c.sum=a.sum+b.sum;
    c.pref=max(a.pref, a.sum+b.pref);
    c.suf=max(b.suf, a.suf+b.sum);
    c.ans=max({a.ans, b.ans, a.suf+b.pref});
    return c;
}
inline void push(int v, int l, int r) {
    if (lz[v]==B)
        return;
    if (l^r) {
        int m=l+r>>1;
        t[v<<1].sum=1LL*(m-l+1)*lz[v];
        t[v<<1|1].sum=1LL*(r-m)*lz[v];
        t[v<<1].ans=t[v<<1].pref=t[v<<1].suf=max(0LL, t[v<<1].sum);
        t[v<<1|1].ans=t[v<<1|1].pref=t[v<<1|1].suf=max(0LL, t[v<<1|1].sum);
        lz[v<<1]=lz[v<<1|1]=lz[v];
    }
    lz[v]=B;
}
void upd(int l, int r, ll x, int lo=0, int hi=n-1, int v=1) {
    if (l>hi || r<lo)
        return;
    if (lo>=l && hi<=r) {
        t[v].sum=1LL*(hi-lo+1)*x;
        t[v].ans=t[v].pref=t[v].suf=max(0LL, t[v].sum);
        lz[v]=x;
        return;
    }
    push(v, lo, hi);
    int m=lo+hi>>1;
    upd(l, r, x, lo, m, v<<1);
    upd(l, r, x, m+1, hi, v<<1|1);
    t[v]=merge(t[v<<1], t[v<<1|1]);
}

int main() {
    fill(lz, lz+(mxN<<2), B);
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> q;
    while (q--) {
        int l, r, v;
        cin >> l >> r >> v, --r;
        upd(l, r, v);
        cout << t[1].ans << '\n';
    }
}

