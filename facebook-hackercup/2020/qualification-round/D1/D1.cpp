//Way overkilled this with lazy seg
#include <bits/stdc++.h>
using namespace std;
using ll=long long;

ifstream fin("input.txt");
ofstream fout("output.txt");

const int mxN=1e6+1;
const ll INF=0x3f3f3f3f3f3f3f3f;
ll n, m, a[mxN], seg[mxN*4], lazy[mxN*4];

void upd(int l, int r, ll x, int lo=0, int hi=n-1, int v=1) {
    if (lazy[v]!=INF) {
        seg[v]=min(seg[v], lazy[v]);
        if (lo!=hi) {
            lazy[v*2]=min(lazy[v*2], lazy[v]);
            lazy[v*2+1]=min(lazy[v*2+1], lazy[v]);
        }
        lazy[v]=INF;
    }
    if (r<lo || l>hi)
        return;
    if (lo>=l && hi<=r) {
        seg[v]=min(seg[v], x);
        if (lo!=hi) {
            lazy[v*2]=min(lazy[v*2], x);
            lazy[v*2+1]=min(lazy[v*2+1], x);
        }
        return;
    }
    int mid=(lo+hi)/2;
    upd(l, r, x, lo, mid, v*2);
    upd(l, r, x, mid+1, hi, v*2+1);
    seg[v]=min(seg[v*2], seg[v*2+1]);
}

ll query(int i, int lo=0, int hi=n-1, int v=1) {
    if (lazy[v]!=INF) {
        seg[v]=min(seg[v], lazy[v]);
        if (lo!=hi) {
            lazy[v*2]=min(lazy[v*2], lazy[v]);
            lazy[v*2+1]=min(lazy[v*2+1], lazy[v]);
        }
        lazy[v]=INF;
    }
    if (lo==hi)
        return seg[v];
    int mid=(lo+hi)/2;
    if (i<=mid)
        return query(i, lo, mid, v*2);
    else
        return query(i, mid+1, hi, v*2+1);
}

ll solve() {
    memset(seg, 0x3f, sizeof(seg));
    memset(lazy, 0x3f, sizeof(lazy));
    upd(0, m, 0);
    for (int i=0; i<n; ++i) {
        if (!a[i])
            continue;
        ll cur=query(i);
        if (cur==INF)
            return -1;
        cur+=a[i];
        upd(i, m+i, cur);
    }
    ll ans=query(n-1);
    return (ans==INF)?-1:ans;
}

int main() {
    int t; fin >> t;
    for (int tt=1; tt<=t; ++tt) {
        fin >> n >> m;
        for (int i=0; i<n; ++i)
            fin >> a[i];
        fout << "Case #" << tt << ": " << solve() << '\n';
    }
}

