#include <bits/stdc++.h>
using namespace std;
using ll=long long;

const int mxN=1e5+1;
int n, q;
ll t[mxN<<2], lz[mxN<<2];

void push(int v, int l, int r) {
    if (l^r) {
        lz[v<<1]+=lz[v];
        lz[v<<1|1]+=lz[v];
        t[v<<1]+=lz[v];
        t[v<<1|1]+=lz[v];
    }
    lz[v]=0;
}
void upd(int l, int r, ll x, int lo=0, int hi=n-1, int v=1) {
    if (l>hi || r<lo)
        return;
    if (lo>=l && hi<=r) {
        t[v]+=x, lz[v]+=x;
        return;
    }
    push(v, lo, hi);
    int m=lo+hi>>1;
    upd(l, r, x, lo, m, v<<1);
    upd(l, r, x, m+1, hi, v<<1|1);
    t[v]=min(t[v<<1], t[v<<1|1]);
}
ll query(int l, int r, int lo=0, int hi=n-1, int v=1) {
    if (l>hi || r<lo)
        return LLONG_MAX;
    if (lo>=l && hi<=r)
        return t[v];
    push(v, lo, hi);
    int m=lo+hi>>1;
    return min(query(l, r, lo, m, v<<1), query(l, r, m+1, hi, v<<1|1));
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> q;
    while (q--) {
        int a, b, c;
        cin >> a >> b >> c, --c;
        if (a==1) {
            int d; cin >> d;
            upd(b, c, d);
        }
        else
            cout << query(b, c) << '\n';
    }
}

