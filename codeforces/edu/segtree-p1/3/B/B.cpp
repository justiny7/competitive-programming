#include <bits/stdc++.h>
using namespace std;

const int mxN=1e5+1;
int n, a[mxN], seg[mxN*4], ans[mxN];

void upd(int i, int x, int l=0, int r=n-1, int v=1) {
    if (l==r) {
        seg[v]=x;
        return;
    }
    int m=l+r>>1;
    if (i<=m)
        upd(i, x, l, m, v<<1);
    else
        upd(i, x, m+1, r, v<<1|1);
    seg[v]=seg[v<<1]+seg[v<<1|1];
}
int query(int k, int l=0, int r=n-1, int v=1) {
    if (r==l)
        return l;
    int m=l+r>>1;
    if (seg[v<<1|1]>k)
        return query(k, m+1, r, v<<1|1);
    else
        return query(k-seg[v<<1|1], l, m, v<<1);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for (int i=0; i<n; ++i)
        cin >> a[i], upd(i, 1);
    for (int i=n-1; ~i; --i) {
        ans[i]=query(a[i]);
        upd(ans[i], 0);
    }
    for (int i=0; i<n; ++i)
        cout << ans[i]+1 << (i<n-1?" ":"\n");
}

