#include <bits/stdc++.h>
using namespace std;

const int mxN=2e5+1;
int n, q, tt, a[mxN], head[mxN], dep[mxN], par[mxN], pos[mxN], t[mxN<<2];
vector<int> adj[mxN];

void upd(int i, int x, int l=0, int r=n-1, int v=1) {
    if (l==r) {
        t[v]=x;
        return;
    }
    int m=l+r>>1;
    if (i<=m)
        upd(i, x, l, m, v<<1);
    else
        upd(i, x, m+1, r, v<<1|1);
    t[v]=max(t[v<<1], t[v<<1|1]);
}
int tquery(int l, int r, int lo=0, int hi=n-1, int v=1) {
    if (l>hi || r<lo)
        return 0;
    if (lo>=l && hi<=r)
        return t[v];
    int m=lo+hi>>1;
    return max(tquery(l, r, lo, m, v<<1), tquery(l, r, m+1, hi, v<<1|1));
}
int dfs(int v=1) {
    int sz=1, mx=0;
    for (int &u:adj[v]) {
        if (u^par[v]) {
            par[u]=v, dep[u]=dep[v]+1;
            int c=dfs(u);
            sz+=c;
            if (c>mx)
                mx=c, swap(adj[v][0], u);
        }
    }
    return sz;
}
void dfs2(int v=1, int h=1) {
    head[v]=h, pos[v]=tt++;
    bool f=1;
    for (int u:adj[v])
        if (u^par[v])
            dfs2(u, f?h:u), f=0;
}
int query(int a, int b) {
    int ret=0;
    for (; head[a]^head[b]; b=par[head[b]]) {
        if (dep[head[a]]>dep[head[b]])
            swap(a, b);
        ret=max(ret, tquery(pos[head[b]], pos[b]));
    }
    if (dep[a]>dep[b])
        swap(a, b);
    return max(ret, tquery(pos[a], pos[b]));
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> q;
    for (int i=1; i<=n; ++i)
        cin >> a[i];
    for (int i=1; i<n; ++i) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    dfs(); dfs2();
    for (int i=1; i<=n; ++i)
        upd(pos[i], a[i]);
    while (q--) {
        int t, x, y;
        cin >> t >> x >> y;
        if (t&1)
            upd(pos[x], y);
        else
            cout << query(x, y) << " ";
    }
    cout << '\n';
}

