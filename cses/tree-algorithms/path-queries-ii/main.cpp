#include <bits/stdc++.h>
using namespace std;

const int mxN=2e5+1;
int n, q, tt, a[mxN], head[mxN], dep[mxN], par[mxN], pos[mxN], t[mxN<<1];
vector<int> adj[mxN];

void build() {
    for (int i=n-1; i; --i)
        t[i]=max(t[i<<1], t[i<<1|1]);
}
void upd(int i, int x) {
    for (t[i+=n]=x; i>1; i>>=1)
        t[i>>1]=max(t[i], t[i^1]);
}
int tquery(int l, int r) {
    int ret=0;
    for (l+=n, r+=n+1; l<r; l>>=1, r>>=1) {
        if (l&1)
            ret=max(ret, t[l++]);
        if (r&1)
            ret=max(ret, t[--r]);
    }
    return ret;
}
int dfs(int v=1) {
    int sz=1, mx=0, c;
    for (int &u:adj[v]) {
        if (u^par[v]) {
            par[u]=v, dep[u]=dep[v]+1;
            sz+=(c=dfs(u));
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
        t[pos[i]+n]=a[i];
    build();
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

