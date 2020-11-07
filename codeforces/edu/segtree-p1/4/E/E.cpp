#include <bits/stdc++.h>
using namespace std;

const int mxN=1e5+1, INF=0x3f3f3f3f;
int n, q, t[mxN<<2];

void upd(int i, int x, int l=0, int r=n-1, int v=1) {
    if (l==r) {
        t[v]=x;
        return;
    }
    int m=l+r>>1;
    if (i<=m)
        upd(i, x, l, m, v<<1);
    else
        upd(i, x, m+1, r, v<<1|1);
    t[v]=min(t[v<<1], t[v<<1|1]);
}
int query(int l, int r, int x, int lo=0, int hi=n-1, int v=1) {
    if (l>hi || r<lo)
        return 0;
    if (lo==hi)
        return t[v]=INF, 1;
    int tot=0, m=lo+hi>>1;
    if (t[v<<1]<=x)
        tot+=query(l, r, x, lo, m, v<<1);
    if (t[v<<1|1]<=x)
        tot+=query(l, r, x, m+1, hi, v<<1|1);
    return tot;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> q;
    for (int i=0; i<n; ++i)
        upd(i, INF);
    while (q--) {
        int a, b, c;
        cin >> a >> b >> c;
        if (a==1)
            upd(b, c);
        else {
            int d; cin >> d;
            cout << query(b, c-1, d) << '\n';
        }
    }
}

