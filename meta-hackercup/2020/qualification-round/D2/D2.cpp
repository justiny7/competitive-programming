//Looked at hint to solve this
#include <bits/stdc++.h>
#define pb push_back
using namespace std;
using ll=long long;

ifstream fin("input.txt");
ofstream fout("output.txt");

const int mxN=1e6+1;
const ll INF=0x3f3f3f3f3f3f3f3f;
ll n, m, a, b, c[mxN], seg[mxN*8], par[mxN]; //segtree on path from A->B
vector<vector<int>> adj;
vector<int> path;

void upd(int i, ll x, int l=0, int r=n-1, int v=1) { //segtree stuff
    if (l==r) {
        seg[v]=min(seg[v], x);
        return;
    }
    int mid=(l+r)/2;
    if (i<=mid)
        upd(i, x, l, mid, v*2);
    else
        upd(i, x, mid+1, r, v*2+1);
    seg[v]=min(seg[v*2], seg[v*2+1]);
}

ll query(int l, int r, int lo=0, int hi=n-1, int v=1) {
    if (l>hi || r<lo)
        return INF;
    if (lo>=l && r>=hi)
        return seg[v];
    int mid=(lo+hi)/2;
    return min(query(l, r, lo, mid, v*2), query(l, r, mid+1, hi, v*2+1));
}

void get_path(int v=b, int p=-1) { //Builds par array
    par[v]=p;
    for (int u:adj[v])
        if (u!=p)
            get_path(u, v);
}

void dfs(int i, int v, int p=-1, int d=0) { //dfs's from i'th node of array
    if (d>m) //if we are more than d away from path[i], then return
        return;
    if (v==a || c[v]) { //if there's a gas station here/we're at the start...
        ll q=query(i+d, i+d+m);
        if (q<INF) //and we can update a value along the path from here...
            upd(i+m-d, c[v]+q); //then update the value m-d down the path from i
    }
    for (int u:adj[v]) //for each node in the subtree...
        if (u!=p && (!i || u!=path[i-1]) && (i==path.size()-1 || u!=path[i+1]))
            dfs(i, u, v, d+1); //if it's not the par node or a node on the path, then dfs from it
}

ll solve() {
    c[a]=c[b]=0;
    get_path();
    int cur=a;
    while (cur!=b)
        path.pb(cur), cur=par[cur];
    path.pb(b);
    upd(0, 0);
    for (int i=0; i<path.size(); ++i)
        dfs(i, path[i]);
    ll ans=query(path.size()-1, path.size()+m);
    return (ans==INF)?-1:ans;
}

int main() {
    int t; fin >> t;
    for (int tt=1; tt<=t; ++tt) {
        memset(seg, 0x3f, sizeof(seg));
        path.clear();
        adj.clear();
        fin >> n >> m >> a >> b;
        adj.resize(n+1);
        for (int i=1; i<=n; ++i) {
            int a;
            fin >> a >> c[i];
            if (a) {
                adj[i].pb(a);
                adj[a].pb(i);
            }
        }
        fout << "Case #" << tt << ": " << solve() << '\n';
    }
}
