#include <bits/stdc++.h>
using namespace std;

const int mxN=2e5+1;
int n, q, a[mxN];
struct node {
    int pre0, pre1, suf0, suf1, mx0, mx1;
} t[mxN<<2];

inline node merge(node a, node b) {
    node ret;
    ret.pre0=a.pre0+(a.mx1?0:b.pre0);
    ret.pre1=a.pre1+(a.mx0?0:b.pre1);
    ret.suf0=b.suf0+(b.mx1?0:a.suf0);
    ret.suf1=b.suf1+(b.mx0?0:a.suf1);
    ret.mx0=max({a.mx0, b.mx0, a.suf0+b.pre0});
    ret.mx1=max({a.mx1, b.mx1, a.suf1+b.pre1});
    return ret;
}
void build(int l=0, int r=n-1, int v=1) {
    if (l==r) {
        t[v].pre1=t[v].suf1=t[v].mx1=a[l];
        t[v].pre0=t[v].suf0=t[v].mx0=1-a[l];
        return;
    }
    int m=l+r>>1;
    build(l, m, v<<1);
    build(m+1, r, v<<1|1);
    t[v]=merge(t[v<<1], t[v<<1|1]);
}
void upd(int i, int l=0, int r=n-1, int v=1) {
    if (l==r) {
        a[i]^=1;
        t[v].pre1=t[v].suf1=t[v].mx1=a[i];
        t[v].pre0=t[v].suf0=t[v].mx0=1-a[i];
        return;
    }
    int m=l+r>>1;
    if (i<=m)
        upd(i, l, m, v<<1);
    else
        upd(i, m+1, r, v<<1|1);
    t[v]=merge(t[v<<1], t[v<<1|1]);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    string s; cin >> s, n=s.size();
    for (int i=0; i<n; ++i)
        a[i]=(s[i]-'0');
    build();
    cin >> q;
    while (q--) {
        int x; cin >> x, --x;
        upd(x);
        cout << max(t[1].mx0, t[1].mx1) << " \n"[q==0];
    }
}

