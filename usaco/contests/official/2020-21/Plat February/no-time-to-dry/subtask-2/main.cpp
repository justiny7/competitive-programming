#include <bits/stdc++.h>
using namespace std;

const int mxN=5e3+1, INF=0x3f3f3f3f;
int n, q, a[mxN], lst[mxN], t[mxN<<1];

void upd(int i, int x) {
    for (t[i+=n]=x; i>1; i>>=1)
        t[i>>1]=min(t[i], t[i^1]);
}
int query(int l, int r) {
    int ret=INF;
    for (l+=n, r+=n+1; l<r; l>>=1, r>>=1) {
        if (l&1)
            ret=min(ret, t[l++]);
        if (r&1)
            ret=min(ret, t[--r]);
    }
    return ret;
}

int solve(int l, int r) {
    memset(lst, -1, sizeof(lst));
    int ret=0;
    for (int i=l; i<=r; ++i) {
        if (~lst[a[i]]) {
            if (query(lst[a[i]], i)<a[i])
                ++ret;
        }
        else
            ++ret;
        upd(i, a[i]);
        lst[a[i]]=i;
    }
    for (int i=l; i<=r; ++i)
        upd(i, INF);
    return ret;
}

int main() {
    memset(t, 0x3f, sizeof(t));
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> q;
    for (int i=0; i<n; ++i)
        cin >> a[i];
    while (q--) {
        int l, r;
        cin >> l >> r;
        cout << solve(l-1, r-1) << '\n';
    }
}

