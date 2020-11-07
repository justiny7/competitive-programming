//HLD - yay worked first try
#include <bits/stdc++.h>
#define pb push_back
using namespace std;
using ll=long long;

ifstream fin("cowland.in");
ofstream fout("cowland.out");

const int mxN=1e5+1;
ll n, q, t, c[mxN], at[mxN], par[mxN], dep[mxN], nxt[mxN], head[mxN], pos[mxN], seg[mxN*4];
vector<int> adj[mxN];

void build(int v=1, int l=0, int r=n-1) {
    if (l==r) {
        seg[v]=c[at[l]];
        return;
    }
    int m=(l+r)/2;
    build(v*2, l, m);
    build(v*2+1, m+1, r);
    seg[v]=seg[v*2]^seg[v*2+1];
}

void upd(int i, int x, int l=0, int r=n-1, int v=1) {
    if (l==r) {
        seg[v]=x;
        return;
    }
    int m=(l+r)/2;
    if (i<=m)
        upd(i, x, l, m, v*2);
    else
        upd(i, x, m+1, r, v*2+1);
    seg[v]=seg[v*2]^seg[v*2+1];
}

ll seg_query(int l, int r, int lo=0, int hi=n-1, int v=1) {
    if (l>hi || lo>r)
        return 0;
    if (lo>=l && hi<=r)
        return seg[v];
    int m=(lo+hi)/2;
    return seg_query(l, r, lo, m, v*2)^seg_query(l, r, m+1, hi, v*2+1);
}

ll dfs(int v=1) {
    ll sz=1, mxsz=0;
    for (int u:adj[v])
        if (u^par[v]) {
            par[u]=v, dep[u]=dep[v]+1;
            ll u_sz=dfs(u);
            sz+=u_sz;
            if (u_sz>mxsz)
                mxsz=u_sz, nxt[v]=u;
        }
    return sz;
}

void decomp(int v=1, ll h=1) {
    head[v]=h, at[t]=v, pos[v]=t++;
    if (nxt[v]>=0)
        decomp(nxt[v], h);
    for (int u:adj[v])
        if (u^par[v] && u^nxt[v])
            decomp(u, u);
}

ll query(int a, int b) {
    ll ans=0;
    for (; head[a]^head[b]; b=par[head[b]]) {
        if (dep[head[a]]>dep[head[b]])
            swap(a, b);
        ans^=seg_query(pos[head[b]], pos[b]);
    }
    if (dep[a]>dep[b])
        swap(a, b);
    ans^=seg_query(pos[a], pos[b]);
    return ans;
}

int main() {
    fin >> n >> q;
    for (int i=1; i<=n; ++i)
        fin >> c[i];
    for (int i=1; i<n; ++i) {
        int a, b;
        fin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    memset(nxt, -1, sizeof(nxt));
    dfs(); decomp(); build();
    while (q--) {
        int t, a, b;
        fin >> t >> a >> b;
        if (t==1)
            upd(pos[a], b);
        else
            fout << query(a, b) << '\n';
    }
}

