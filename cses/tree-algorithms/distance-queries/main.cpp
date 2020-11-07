//LCA
#include <bits/stdc++.h>
#define pb push_back
using namespace std;
using pii=pair<int, int>;

const int mxN=2e5+1;
int n, q, seg[mxN*8], dep[mxN], in[mxN];
vector<int> adj[mxN], tour;

void dfs(int v=1, int p=-1, int d=0) {
    dep[v]=d;
    in[v]=tour.size();
    tour.pb(v);
    for (int u:adj[v])
        if (u!=p) {
            dfs(u, v, d+1);
            tour.pb(v);
        }
}

void build(int v=1, int l=0, int r=n-1) {
    if (l==r) {
        seg[v]=tour[l];
        return;
    }
    int mid=(l+r)/2;
    build(v*2, l, mid);
    build(v*2+1, mid+1, r);
    int a=seg[v*2], b=seg[v*2+1];
    seg[v]=(dep[a]<dep[b])?a:b;
}

int query(int l, int r, int lo=0, int hi=n-1, int v=1) {
    if (l>hi || r<lo)
        return -1;
    if (lo>=l && hi<=r)
        return seg[v];
    int mid=(lo+hi)/2,
        a=query(l, r, lo, mid, v*2),
        b=query(l, r, mid+1, hi, v*2+1);
    if (a<0)
        return b;
    if (b<0)
        return a;
    return (dep[a]<dep[b])?a:b;
}

int lca(int a, int b) {
    int l=in[a], r=in[b];
    if (l>r)
        swap(l, r);
    return query(l, r);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> q;
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
        int a, b;
        cin >> a >> b;
        int m=lca(a, b);
        cout << dep[a]+dep[b]-2*dep[m] << '\n';
    }
}
