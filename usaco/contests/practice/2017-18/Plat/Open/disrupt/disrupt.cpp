#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;

const int mxN=5e4+1, INF=0x3f3f3f3f;
int n, m, tt, head[mxN], dep[mxN], par[mxN], pos[mxN], t[mxN<<2], lz[mxN<<2];
pair<int, int> edges[mxN];
vector<int> adj[mxN];

inline void push(int l, int r, int v) {
    if (l^r) {
        lz[v<<1]=min(lz[v<<1], lz[v]);
        lz[v<<1|1]=min(lz[v<<1|1], lz[v]);
        t[v<<1]=min(t[v<<1], lz[v]);
        t[v<<1|1]=min(t[v<<1|1], lz[v]);
    }
    lz[v]=INF;
}
void tupd(int l, int r, int x, int lo=0, int hi=n-1, int v=1) {
    if (l>hi || r<lo)
        return;
    if (lo>=l && hi<=r) {
        t[v]=min(t[v], x), lz[v]=min(lz[v], x);
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
    int sz=1, mx=0;
    for (int &u:adj[v])
        if (u^par[v]) {
            par[u]=v, dep[u]=dep[v]+1;
            int c=dfs(u);
            sz+=c;
            if (c>mx)
                mx=c, swap(adj[v][0], u);
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
void upd(int a, int b, int x) {
    for (; head[a]^head[b]; b=par[head[b]]) {
        if (dep[head[a]]>dep[head[b]])
            swap(a, b);
        tupd(pos[head[b]], pos[b], x);
    }
    if (dep[a]>dep[b])
        swap(a, b);
    if (a^b)
        tupd(pos[a]+1, pos[b], x);
}

int main() {
    memset(t, 0x3f, sizeof(t));
    memset(lz, 0x3f, sizeof(lz));
    ifstream cin("disrupt.in");
    ofstream cout("disrupt.out");
    cin >> n >> m;
    for (int i=1; i<n; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
        edges[i]={a, b};
    }
    dfs(); dfs2();
    while (m--) {
        int a, b, x;
        cin >> a >> b >> x;
        upd(a, b, x);
    }
    for (int i=1; i<n; ++i) {
        if (dep[edges[i].fi]<dep[edges[i].se])
            swap(edges[i].fi, edges[i].se);
        int ans=query(pos[edges[i].fi]);
        cout << (ans^INF?ans:-1) << '\n';
    }
}

