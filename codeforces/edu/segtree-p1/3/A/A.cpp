#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
using pii=pair<int, int>;

const int mxN=1e5+1;
int n, seg[mxN*4], ans[mxN], a[mxN], b[mxN];

bool cmp(int x, int y) {
    return a[x]>a[y];
}

void upd(int i, int l=0, int r=n-1, int v=1) {
    if (l==r) {
        seg[v]=1;
        return;
    }
    int m=(l+r)/2;
    if (i<=m)
        upd(i, l, m, v*2);
    else
        upd(i, m+1, r, v*2+1);
    seg[v]=seg[v*2]+seg[v*2+1];
}
int query(int i, int l=0, int r=n-1, int v=1) {
    if (l>i)
        return 0;
    if (r<=i)
        return seg[v];
    int m=(l+r)/2;
    return query(i, l, m, v*2)+query(i, m+1, r, v*2+1);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for (int i=0; i<n; ++i)
        cin >> a[i], b[i]=i;
    sort(b, b+n, cmp);
    for (int i=0; i<n; ++i) {
        ans[b[i]]=query(b[i]);
        upd(b[i]);
    }
    for (int i=0; i<n; ++i)
        cout << ans[i] << (i<n-1?" ":"\n");
}

