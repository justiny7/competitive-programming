#include <bits/stdc++.h>
using namespace std;
using ll=long long;

const int mxN=1e5+1;
ll n, q, t[mxN*4];

void upd(int i, int x, int l=0, int r=n-1, int v=1) {
    if (l==r) {
        t[v]=(1LL<<x);
        return;
    }
    int m=l+r>>1;
    if (i<=m)
        upd(i, x, l, m, v<<1);
    else
        upd(i, x, m+1, r, v<<1|1);
    t[v]=t[v<<1]|t[v<<1|1];
}
ll query(int l, int r, int lo=0, int hi=n-1, int v=1) {
    if (l>hi || r<lo)
        return 0;
    if (lo>=l && hi<=r)
        return t[v];
    int m=lo+hi>>1;
    return query(l, r, lo, m, v<<1)|query(l, r, m+1, hi, v<<1|1);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> q;
    for (int i=0; i<n; ++i) {
        int a; cin >> a;
        upd(i, a);
    }
    while (q--) {
        int a, b, c;
        cin >> a >> b >> c;
        if (a==1)
            cout << __builtin_popcountll(query(b-1, c-1)) << '\n';
        else
            upd(b-1, c);
    }
}

