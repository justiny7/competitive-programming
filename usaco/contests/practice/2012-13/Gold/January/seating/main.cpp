//Yay worked first try!
#include <bits/stdc++.h>
using namespace std;

const int mxN=5e5+1;
int n, m, ans, lz[mxN<<2];
struct node {
    int pre, suf, mx, tot;
} t[mxN<<2];

inline node comb(node a, node b) {
    node ret;
    ret.pre=a.pre+((a.pre==a.tot)?b.pre:0);
    ret.suf=b.suf+((b.suf==b.tot)?a.suf:0);
    ret.mx=max({a.mx, b.mx, a.suf+b.pre});
    ret.tot=a.tot+b.tot;
    return ret;
}
inline void push(int l, int r, int v) {
    if (l^r && ~lz[v]) {
        int m=l+r>>1;
        lz[v<<1]=lz[v<<1|1]=lz[v];
        t[v<<1].pre=t[v<<1].suf=t[v<<1].mx=(m-l+1)*lz[v];
        t[v<<1].tot=m-l+1;
        t[v<<1|1].pre=t[v<<1|1].suf=t[v<<1|1].mx=(r-m)*lz[v];
        t[v<<1|1].tot=r-m;
    }
    lz[v]=-1;
}
void upd(int l, int r, int x, int lo=0, int hi=n-1, int v=1) {
    if (l>hi || r<lo)
        return;
    push(lo, hi, v);
    if (lo>=l && hi<=r) {
        t[v].pre=t[v].suf=t[v].mx=(hi-lo+1)*x;
        t[v].tot=(hi-lo+1);
        lz[v]=x;
        return;
    }
    int m=lo+hi>>1;
    upd(l, r, x, lo, m, v<<1);
    upd(l, r, x, m+1, hi, v<<1|1);
    t[v]=comb(t[v<<1], t[v<<1|1]);
}
int query(int x, int l=0, int r=n-1, int v=1) {
    push(l, r, v);
    int m=l+r>>1;
    if (t[v<<1].mx>=x)
        return query(x, l, m, v<<1);
    else if (t[v<<1].suf+t[v<<1|1].pre>=x)
        return m-t[v<<1].suf+1;
    else if (t[v<<1|1].mx>=x)
        return query(x, m+1, r, v<<1|1);
    else
        return -1;
}

int main() {
    memset(lz, -1, sizeof(lz));
    ifstream cin("seating.in");
    ofstream cout("seating.out");
    cin >> n >> m;
    upd(0, n-1, 1);
    while (m--) {
        char c; cin >> c;
        if (c=='A') {
            int sz, ret;
            cin >> sz;
            ret=query(sz);
            if (~ret)
                upd(ret, ret+sz-1, 0);
            else
                ++ans;
        }
        else {
            int l, r;
            cin >> l >> r, --l, --r;
            upd(l, r, 1);
        }
    }
    cout << ans << '\n';
}

