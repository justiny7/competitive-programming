#include <bits/stdc++.h>
using namespace std;
using ll=long long;

const int mxN=2e5+1;
int n;
ll a[mxN], h[mxN], t[mxN<<2];

void upd(int i, ll x, int l=0, int r=n-1, int v=1) {
    if (l==r) {
        t[v]=x;
        return;
    }
    int m=l+r>>1;
    if (i<=m)
        upd(i, x, l, m, v<<1);
    else
        upd(i, x, m+1, r, v<<1|1);
    t[v]=max(t[v<<1], t[v<<1|1]);
}
ll query(int l, int r, int lo=0, int hi=n-1, int v=1) {
    if (l>hi || r<lo)
        return 0;
    if (lo>=l && hi<=r)
        return t[v];
    int m=lo+hi>>1;
    return max(query(l, r, lo, m, v<<1), query(l, r, m+1, hi, v<<1|1));
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for (int i=0; i<n; ++i)
        cin >> h[i];
    for (int i=0; i<n; ++i)
        cin >> a[i];
    for (int i=0; i<n; ++i)
        upd(h[i], query(0, h[i]-1)+a[i]);
    cout << query(0, n-1) << '\n';
}

