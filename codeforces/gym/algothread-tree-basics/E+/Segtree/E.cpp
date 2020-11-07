#include <bits/stdc++.h>
#define pb push_back
using namespace std;
using db=double;

const int mxN=3e5+1;
int n, q, t, in[mxN], out[mxN];
db seg[mxN*8];
vector<int> adj[mxN];

void dfs(int v=1, int p=0) {
    in[v]=t++;
    for (int u:adj[v])
        if (u^p)
            dfs(u, v);
    out[v]=t++;
}

void upd(int i, db x, int l=0, int r=2*n-1, int v=1) {
    if (l==r) {
        seg[v]=log(x);
        return;
    }
    int m=(l+r)/2;
    if (i<=m)
        upd(i, x, l, m, v*2);
    else
        upd(i, x, m+1, r, v*2+1);
    seg[v]=seg[v*2]+seg[v*2+1];
}

db query(int l, int r, int lo=0, int hi=2*n-1, int v=1) {
    if (lo>r || hi<l)
        return 0;
    if (lo>=l && hi<=r)
        return seg[v];
    int m=(lo+hi)/2;
    return query(l, r, lo, m, v*2)+query(l, r, m+1, hi, v*2+1);
}

int main() {
    cout << setprecision(12) << fixed;
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for (int i=1; i<n; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    dfs();
    cin >> q;
    while (q--) {
        int p, a, b;
        cin >> p >> a >> b;
        if (p==1)
            upd(in[a], db(b));
        else {
            db c=query(in[a], out[a]), d=query(in[b], out[b]);
            if (c-d>=log(1e9))
                cout << 1e9 << '\n';
            else
                cout << exp(c-d) << '\n';
        }
    }
}

