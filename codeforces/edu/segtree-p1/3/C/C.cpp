#include <bits/stdc++.h>
using namespace std;

const int mxN=2e5+1;
int n, seg[mxN*4], lst[mxN], ans[mxN];

void upd(int i, int l=0, int r=2*n-1, int v=1) {
    if (l==r) {
        ++seg[v];
        return;
    }
    int m=l+r>>1;
    if (i<=m)
        upd(i, l, m, v<<1);
    else
        upd(i, m+1, r, v<<1|1);
    seg[v]=seg[v<<1]+seg[v<<1|1];
}
int query(int l, int r, int lo=0, int hi=2*n-1, int v=1) {
    if (l>hi || r<lo)
        return 0;
    if (lo>=l && hi<=r)
        return seg[v];
    int m=lo+hi>>1;
    return query(l, r, lo, m, v<<1)+query(l, r, m+1, hi, v<<1|1);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    memset(lst, -1, sizeof(lst));
    for (int i=0; i<n*2; ++i) {
        int a; cin >> a;
        if (lst[a]<0) {
            lst[a]=i;
            continue;
        }
        ans[a]=query(lst[a], i);
        upd(lst[a]);
    }
    for (int i=1; i<=n; ++i)
        cout << ans[i] << (i^n?" ":"\n");
}

