//Idk the smart way to do this problem so I'll try killing it with HLD
//I mean it worked (first try too, minus the compilation error!) so xd
#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
using namespace std;
using pii=pair<int, int>;

const int mxN=1e5+1;
int n, m, t, c[mxN], at[mxN], par[mxN], dep[mxN], nxt[mxN], head[mxN], pos[mxN], seg[mxN*4];
pii types[mxN];
vector<int> adj[mxN];
bool ans[mxN];
struct q {
    int a, b, x, ind;
    bool operator<(const q& k) const {
        return x<k.x;
    }
} queries[mxN];

void upd(int i, int x, int l=0, int r=n-1, int v=1) {
    if (l==r) {
        seg[v]=x;
        return;
    }
    int mid=(l+r)/2;
    if (i<=mid)
        upd(i, x, l, mid, v*2);
    else
        upd(i, x, mid+1, r, v*2+1);
    seg[v]=max(seg[v*2], seg[v*2+1]);
}

int squery(int l, int r, int lo=0, int hi=n-1, int v=1) {
    if (l>hi || r<lo)
        return -1;
    if (lo>=l && hi<=r)
        return seg[v];
    int mid=(lo+hi)/2;
    return max(squery(l, r, lo, mid, v*2), squery(l, r, mid+1, hi, v*2+1));
}

int dfs(int v=1) {
    int sz=1, mxsz=0;
    for (int u:adj[v])
        if (u^par[v]) {
            par[u]=v, dep[u]=dep[v]+1;
            int u_sz=dfs(u);
            sz+=u_sz;
            if (u_sz>mxsz)
                mxsz=u_sz, nxt[v]=u;
        }
    return sz;
}

void decomp(int v=1, int h=1) {
    head[v]=h, at[t]=v, pos[v]=t++;
    if (nxt[v]>=0)
        decomp(nxt[v], h);
    for (int u:adj[v])
        if (u^par[v] && u^nxt[v])
            decomp(u, u);
}

int query(int a, int b) {
    int ans=0;
    for (; head[a]^head[b]; b=par[head[b]]) {
        if (dep[head[a]]>dep[head[b]])
            swap(a, b);
        ans=max(ans, squery(pos[head[b]], pos[b]));
    }
    if (dep[a]>dep[b])
        swap(a, b);
    ans=max(ans, squery(pos[a], pos[b]));
    return ans;
}

int main() {
    ifstream cin("milkvisits.in");
    ofstream cout("milkvisits.out");
    cin >> n >> m;
    for (int i=1; i<=n; ++i)
        cin >> types[i].fi, types[i].se=i;
    sort(types, types+n);
    for (int i=1; i<n; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    memset(nxt, -1, sizeof(nxt));
    dfs(); decomp();
    for (int i=0; i<m; ++i)
        cin >> queries[i].a >> queries[i].b >> queries[i].x, queries[i].ind=i;
    sort(queries, queries+m);
    for (int i=1, j=1, k=0; i<=n; ++i) {
        while (types[j].fi==i)
            upd(pos[types[j++].se], i);
        while (queries[k].x==i)
            ans[queries[k].ind]=(query(queries[k].a, queries[k].b)==i), ++k;
    }
    for (int i=0; i<m; ++i)
        cout << ans[i];
    cout << '\n';
}

