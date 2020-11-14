#include <bits/stdc++.h>
using namespace std;

const int mxN=1e5+1;
int n, q, cnt[mxN], t[mxN<<2], arr[mxN];
bool mk[mxN<<2];

inline void push(int l, int r, int v) {
    if (mk[v] && (l^r)) {
        t[v<<1]=t[v<<1|1]=t[v];
        mk[v<<1]=mk[v<<1|1]=1;
    }
    mk[v]=0;
}
void upd(int l, int r, int x, int lo=0, int hi=n-1, int v=1) {
    if (l>hi || r<lo)
        return;
    if (lo>=l && hi<=r) {
        t[v]=x, mk[v]=1;
        return;
    }
    push(lo, hi, v);
    int m=lo+hi>>1;
    upd(l, r, x, lo, m, v<<1);
    upd(l, r, x, m+1, hi, v<<1|1);
}
int get(int i, int l=0, int r=n-1, int v=1) {
    if (l==r)
        return t[v];
    push(l, r, v);
    int m=l+r>>1;
    if (i<=m)
        return get(i, l, m, v<<1);
    else
        return get(i, m+1, r, v<<1|1);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> q;
    for (int i=0; i<n; ++i) {
        cin >> arr[i];
        upd(i, i, arr[i]);
    }
    while (q--) {
        int a, b, c;
        cin >> a >> b >> c, --a, --b;
        upd(a, b, c);
        ++cnt[a], --cnt[b+1];
    }
    for (int i=1; i<n; ++i)
        cnt[i]+=cnt[i-1];
    for (int i=0; i<n; ++i) {
        if ((cnt[i]&1)^bool(arr[i]))
            cout << get(i);
        else
            cout << 0;
        cout << " \n"[i==n-1];
    }
}

