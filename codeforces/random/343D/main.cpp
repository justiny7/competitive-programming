#include <bits/stdc++.h>
using namespace std;

const int mxN=5e5+1;
int n, q, tt, head[mxN], dep[mxN], par[mxN], in[mxN], out[mxN], t[mxN<<2], lz[mxN<<2];
vector<int> adj[mxN];

inline void push(int l, int r, int v) {
    if (l^r && ~lz[v]) {
        lz[v<<1]=lz[v<<1|1]=lz[v];
        t[v<<1]=t[v<<1|1]=lz[v];
    }
    lz[v]=-1;
}
void tupd(int l, int r, int x, int lo=0, int hi=n-1, int v=1) {
    if (l>hi || r<lo)
        return;
    if (lo>=l && hi<=r) {
        t[v]=lz[v]=x;
        return;
    }
    push(lo, hi, v);
    int m=lo+hi>>1;
    tupd(l, r, x, lo, m, v<<1);
    tupd(l, r, x, m+1, hi, v<<1|1);
}
int query(int i, int l=0, int r=n-1, int v=1) {
    push(l, r, v);
    if (l==r)
        return t[v];
    int m=l+r>>1;
    if (i<=m)
        return query(i, l, m, v<<1);
    else
        return query(i, m+1, r, v<<1|1);
}

int dfs(int v=1) {
    int sz=1, mx=0, c;
    for (int &u:adj[v])
        if (u^par[v]) {
            par[u]=v, dep[u]=dep[v]+1;
            sz+=(c=dfs(u));
            if (c>mx)
                mx=c, swap(adj[v][0], u);
        }
    return sz;
}
void dfs2(int v=1, int h=1) {
    head[v]=h, in[v]=tt++;
    bool f=1;
    for (int u:adj[v])
        if (u^par[v])
            dfs2(u, f?h:u), f=0;
    out[v]=tt;
}
void upd(int a, int b, int x) {
    for (; head[a]^head[b]; b=par[head[b]]) {
        if (dep[head[a]]>dep[head[b]])
            swap(a, b);
        tupd(in[head[b]], in[b], x);
    }
    if (dep[a]>dep[b])
        swap(a, b);
    tupd(in[a], in[b], x);
}

int main() {
    memset(lz, -1, sizeof(lz));
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for (int i=1; i<n; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(); dfs2();
    cin >> q;
    while (q--) {
        int t, x;
        cin >> t >> x;
        if (t==1)
            tupd(in[x], out[x]-1, 1);
        else if (t==2)
            upd(1, x, 0);
        else
            cout << query(in[x]) << '\n';
    }
}

