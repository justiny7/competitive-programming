//NUKE WITH HLD
//Finally got it to work after fixing a buncha stupid bugs
#include <bits/stdc++.h>
#define pb push_back
using namespace std;

const int mxN=1e5+1;
int n, m, tt, nxt[mxN], head[mxN], dep[mxN], par[mxN], pos[mxN], t[mxN<<2];
pair<int, int> c[mxN];
array<int, 4> queries[mxN];
vector<int> adj[mxN];
string ans;

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
int dfs(int v=0) {
    int sz=1, mx=0;
    for (int u:adj[v])
        if (u^par[v]) {
            par[u]=v, dep[u]=dep[v]+1;
            int c=dfs(u);
            sz+=c;
            if (c>mx)
                mx=c, nxt[v]=u;
        }
    return sz;
}
void dfs2(int v=0, int h=0) {
    head[v]=h, pos[v]=tt++;
    if (~nxt[v])
        dfs2(nxt[v], h);
    for (int u:adj[v])
        if (u^par[v] && u^nxt[v])
            dfs2(u, u);
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
    memset(nxt, -1, sizeof(nxt));
    ifstream cin("milkvisits.in");
    ofstream cout("milkvisits.out");
    cin >> n >> m;
    ans.resize(m);
    for (int i=0; i<n; ++i)
        cin >> c[i].first, c[i].second=i;
    for (int i=1; i<n; ++i) {
        int a, b;
        cin >> a >> b, --a, --b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    dfs(), dfs2();
    for (int i=0; i<m; ++i) {
        int x, y, z;
        cin >> x >> y >> z, --x, --y;
        queries[i]={z, x, y, i};
    }
    sort(queries, queries+m);
    sort(c, c+n);
    for (int i=0, j=0; i<m; ++i) {
        while (j<n && c[j].first<=queries[i][0])
            upd(pos[c[j].second], c[j].first), ++j;
        ans[queries[i][3]]=(query(queries[i][1], queries[i][2])==queries[i][0]?'1':'0');
    }
    cout << ans << '\n';
}

