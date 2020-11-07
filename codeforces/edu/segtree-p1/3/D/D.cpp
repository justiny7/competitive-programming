#include <bits/stdc++.h>
using namespace std;

const int mxN=2e5+1;
int n, a[mxN], lst[mxN], seg[mxN*4], ans[mxN];

void upd(int i, int x, int l=0, int r=n*2-1, int v=1) {
    if (l==r) {
        seg[v]+=x;
        return;
    }
    int m=l+r>>1;
    if (i<=m)
        upd(i, x, l, m, v<<1);
    else
        upd(i, x, m+1, r, v<<1|1);
    seg[v]=seg[v<<1]+seg[v<<1|1];
}
int query(int l, int r, int lo=0, int hi=n*2-1, int v=1) {
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
    for (int t=0; t<2; ++t) {
        memset(lst, -1, sizeof(lst));
        for (int i=0; i<n<<1; ++i) {
            if (!t)
                cin >> a[i];
            if (lst[a[i]]<0) {
                lst[a[i]]=i;
                upd(i, 1);
                continue;
            }
            ans[a[i]]+=query(lst[a[i]]+1, i);
            upd(lst[a[i]], -1);
        }
        reverse(a, a+(n<<1));
    }
    for (int i=1; i<=n; ++i)
        cout << ans[i] << (i^n?" ":"\n");
}

