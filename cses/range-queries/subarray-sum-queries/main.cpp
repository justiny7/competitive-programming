//I like this problem lol
#include <bits/stdc++.h>
using namespace std;
using ll=long long;

struct node {
    ll sum, pref, suf, ans;
};

node merge(node a, node b) {
    node c;
    c.sum=a.sum+b.sum;
    c.pref=max(a.pref, a.sum+b.pref);
    c.suf=max(b.suf, b.sum+a.suf);
    c.ans=max({a.ans, b.ans, a.suf+b.pref});
    return c;
}

node make(ll v) {
    node a;
    a.sum=v;
    a.pref=a.suf=a.ans=max(v, 0LL);
    return a;
}

const int mxN=2e5+1;
ll n, m, a[mxN];
node seg[mxN*4];

void build(int v=1, int l=0, int r=n-1) {
    if (l==r) {
        seg[v]=make(a[l]);
        return;
    }
    int mid=(l+r)/2;
    build(v*2, l, mid);
    build(v*2+1, mid+1, r);
    seg[v]=merge(seg[v*2], seg[v*2+1]);
}

void upd(ll ind, ll x, int v=1, int l=0, int r=n-1) {
    if (l==r) {
        seg[v]=make(x);
        return;
    }
    int mid=(l+r)/2;
    if (ind<=mid)
        upd(ind, x, v*2, l, mid);
    else
        upd(ind, x, v*2+1, mid+1, r);
    seg[v]=merge(seg[v*2], seg[v*2+1]);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    for (int i=0; i<n; ++i)
        cin >> a[i];
    build();
    while (m--) {
        ll k, x;
        cin >> k >> x, --k;
        upd(k, x);
        cout << seg[1].ans << '\n';
    }
}
