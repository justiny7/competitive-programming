#include <bits/stdc++.h>
using namespace std;

const int mxN=1e5+5;
int n, r, q, t, mxD, a[mxN], dep[mxN], in[mxN], out[mxN];
vector<int> adj[mxN], qu[mxN];
struct node {
    node *l, *r;
    int val;
    node(int v):l(NULL), r(NULL), val(v) {}
    node(node *l, node *r):l(l), r(r), val(INT_MAX) {
        if (l)
            val=min(val, l->val);
        if (r)
            val=min(val, r->val);
    }
};
node* build(int lo=0, int hi=n*2-1) {
    if (lo==hi)
        return new node(INT_MAX);
    int m=lo+hi>>1;
    return new node(build(lo, m), build(m+1, hi));
}
node* upd(node *v, int i, int x, int lo=0, int hi=n*2-1) {
    if (lo==hi)
        return new node(x);
    int m=lo+hi>>1;
    if (i<=m)
        return new node(upd(v->l, i, x, lo, m), v->r);
    else
        return new node(v->l, upd(v->r, i, x, m+1, hi));
}
int query(node *v, int lb, int rb, int lo=0, int hi=n*2-1) {
    if (lb>hi || rb<lo)
        return INT_MAX;
    if (lo>=lb && hi<=rb)
        return v->val;
    int m=lo+hi>>1;
    return min(query(v->l, lb, rb, lo, m), query(v->r, lb, rb, m+1, hi));
}
vector<node*> pst;

void dfs(int v=r, int p=0, int d=1) {
    in[v]=t++;
    dep[v]=d;
    mxD=max(mxD, d);
    qu[d].push_back(v);
    for (int u:adj[v])
        if (u^p)
            dfs(u, v, d+1);
    out[v]=t++;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> r;
    for (int i=1; i<=n; ++i)
        cin >> a[i];
    for (int i=1; i<n; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs();
    pst.push_back(build());
    for (int i=1; i<=mxD; ++i) {
        node *cur=pst.back();
        for (int v:qu[i])
            cur=upd(cur, in[v], a[v]);
        pst.push_back(cur);
    }
    cin >> q;
    int lst=0;
    while (q--) {
        int x, y, v, k;
        cin >> x >> y;
        v=(lst+x)%n+1, k=(y+lst)%n;
        cout << (lst=query(pst[min(dep[v]+k, mxD)], in[v], out[v])) << '\n';
    }
}

