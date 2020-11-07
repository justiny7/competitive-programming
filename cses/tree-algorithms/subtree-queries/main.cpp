#include <bits/stdc++.h>
#define pb push_back
using namespace std;
using ll=long long;

const int mxN=2e5+1;
int n, q, in[mxN], out[mxN], w[mxN], t;
ll seg[mxN*8];
vector<int> adj[mxN], tour;

void dfs(int v=1, int p=-1) {
    in[v]=t++;
    tour.pb(w[v]);
    for (int u:adj[v])
        if (u!=p)
            dfs(u, v);
    out[v]=t++;
    tour.pb(w[v]);
}

void build(int v=1, int l=0, int r=n-1) {
    if (l==r) {
        seg[v]=tour[l];
        return;
    }
    int mid=(l+r)/2;
    build(v*2, l, mid);
    build(v*2+1, mid+1, r);
    seg[v]=seg[v*2]+seg[v*2+1];
}

void upd(int i, ll x, int l=0, int r=n-1, int v=1) {
    if (l==r) {
        seg[v]=x;
        return;
    }
    int mid=(l+r)/2;
    if (i<=mid)
        upd(i, x, l, mid, v*2);
    else
        upd(i, x, mid+1, r, v*2+1);
    seg[v]=seg[v*2]+seg[v*2+1];
}

ll query(int l, int r, int lo=0, int hi=n-1, int v=1) {
    if (lo>r || hi<l)
        return 0;
    if (lo>=l && hi<=r)
        return seg[v];
    int mid=(lo+hi)/2;
    return query(l, r, lo, mid, v*2)+query(l, r, mid+1, hi, v*2+1);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> q;
    for (int i=1; i<=n; ++i)
        cin >> w[i];
    for (int i=1; i<n; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    dfs();
    n=tour.size();
    build();
    while (q--) {
        int t; cin >> t;
        if (t==1) {
            int a, x;
            cin >> a >> x;
            upd(in[a], x);
            upd(out[a], x);
        }
        else {
            int x; cin >> x;
            cout << query(in[x], out[x])/2 << '\n';
        }
    }
}
