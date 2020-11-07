//HLD
#include <bits/stdc++.h>
#define pb push_back
using namespace std;
using ll=long long;

const int mxN=2e5+1;
ll n, q, t, c[mxN], at[mxN], par[mxN], dep[mxN], nxt[mxN], head[mxN], pos[mxN], seg[mxN*4];
vector<int> adj[mxN];

void build(int v=1, int l=0, int r=n-1) {
    if (l==r) {
        seg[v]=c[at[l]];
        return;
    }
    int mid=(l+r)/2;
    build(v*2, l, mid);
    build(v*2+1, mid+1, r);
    seg[v]=seg[v*2]+seg[v*2+1];
}

void upd(int i, int x, int l=0, int r=n-1, int v=1) {
    if (l==r)
        seg[v]=x;
    else {
        int mid=(l+r)/2;
        if (i<=mid)
            upd(i, x, l, mid, v*2);
        else
            upd(i, x, mid+1, r, v*2+1);
        seg[v]=seg[v*2]+seg[v*2+1];
    }
}

ll seg_query(int l, int r, int lo=0, int hi=n-1, int v=1) {
    if (l>hi || r<lo)
        return 0;
    if (lo>=l && hi<=r)
        return seg[v];
    int mid=(lo+hi)/2;
    return seg_query(l, r, lo, mid, v*2)+seg_query(l, r, mid+1, hi, v*2+1);
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

ll query(int v) {
    ll ans=0;
    for (; head[v]>1; v=par[head[v]])
        ans+=seg_query(pos[head[v]], pos[v]);
    ans+=seg_query(pos[1], pos[v]);
    return ans;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> q;
    for (int i=1; i<=n; ++i)
        cin >> c[i];
    for (int i=0; i<n-1; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    memset(nxt, -1, sizeof(nxt));
    dfs(); decomp(); build();
    while (q--) {
        int t; cin >> t;
        if (t==1) {
            int v, x;
            cin >> v >> x;
            upd(pos[v], x);
        }
        else {
            int v; cin >> v;
            cout << query(v) << '\n';
        }
    }
}
