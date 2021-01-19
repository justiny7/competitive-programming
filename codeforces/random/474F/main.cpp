#include <bits/stdc++.h>
#define node array<int, 3>
using namespace std;

const int mxN=1e5+1;
int n, q, a[mxN];
node t[mxN<<2];

inline node merge(node a, node b) {
    node ret;
    if (a[0]==b[0]) {
        ret[0]=a[0];
        ret[1]=a[1]+b[1];
    }
    else {
        if (a[0]>b[0])
            swap(a, b);
        ret[0]=a[0];
        ret[1]=a[1];
    }
    if (~a[2] && ~b[2])
        ret[2]=__gcd(a[2], b[2]);
    else
        ret[2]=(~a[2]?a[2]:b[2]);
    return ret;
}
void build(int l=0, int r=n-1, int v=1) {
    if (l==r) {
        t[v]={a[l], 1, a[l]};
        return;
    }
    int m=l+r>>1;
    build(l, m, v<<1);
    build(m+1, r, v<<1|1);
    t[v]=merge(t[v<<1], t[v<<1|1]);
}
node query(int l, int r, int lo=0, int hi=n-1, int v=1) {
    if (l>hi || r<lo)
        return {INT_MAX, 0, -1};
    if (lo>=l && hi<=r)
        return t[v];
    int m=lo+hi>>1;
    return merge(query(l, r, lo, m, v<<1), query(l, r, m+1, hi, v<<1|1));
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for (int i=0; i<n; ++i)
        cin >> a[i];
    build();
    cin >> q;
    while (q--) {
        int l, r, sub=0;
        cin >> l >> r;
        node ret=query(l-1, r-1);
        if (ret[0]==ret[2])
            sub=ret[1];
        cout << r-l+1-sub << '\n';
    }
}

