#include <bits/stdc++.h>
using namespace std;
using ll=long long;

const int mxN=1e5+1, mxV=41;
ll n, q, a[mxN];
struct node {
    ll freq[mxV], cnt=0;
    node() {
        memset(freq, 0, sizeof(freq));
    }
} t[mxN*4];

node merge(node x, node y) {
    node z;
    ll c=0;
    for (int i=1; i<=40; ++i)
        c+=(y.freq[i]-y.freq[i-1])*(x.freq[40]-x.freq[i]);
    z.cnt=x.cnt+y.cnt+c;
    for (int i=1; i<=40; ++i)
        z.freq[i]=z.freq[i-1]+x.freq[i]+y.freq[i]-x.freq[i-1]-y.freq[i-1];
    return z;
}

void build(int v=1, int l=0, int r=n-1) {
    if (l==r) {
        t[v].freq[a[l]]=1;
        for (int i=1; i<=40; ++i)
            t[v].freq[i]+=t[v].freq[i-1];
        return;
    }
    int m=l+r>>1;
    build(v<<1, l, m);
    build(v<<1|1, m+1, r);
    t[v]=merge(t[v<<1], t[v<<1|1]);
}
void upd(int i, int x, int l=0, int r=n-1, int v=1) {
    if (l==r) {
        t[v]=node();
        t[v].freq[x]=1;
        for (int i=1; i<=40; ++i)
            t[v].freq[i]+=t[v].freq[i-1];
        return;
    }
    int m=l+r>>1;
    if (i<=m)
        upd(i, x, l, m, v<<1);
    else
        upd(i, x, m+1, r, v<<1|1);
    t[v]=merge(t[v<<1], t[v<<1|1]);
}
node query(int l, int r, int lo=0, int hi=n-1, int v=1) {
    if (l>hi || r<lo)
        return node();
    if (lo>=l && hi<=r)
        return t[v];
    int m=lo+hi>>1;
    return merge(query(l, r, lo, m, v<<1), query(l, r, m+1, hi, v<<1|1));
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> q;
    for (int i=0; i<n; ++i)
        cin >> a[i];
    build();
    while (q--) {
        int x, y, z;
        cin >> x >> y >> z;
        if (x==1)
            cout << query(y-1, z-1).cnt << '\n';
        else
            upd(y-1, z);
    }
}

