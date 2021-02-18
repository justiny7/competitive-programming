//Yo wut it actually worked first try xd
#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pl=pair<ll, ll>;

const int mxN=2e5+5;
int n;
ll mx, ans[mxN];
vector<pl> adj[mxN];
vector<int> parents;
struct HLD { //structs to separate the BIT's
    int tt, head[mxN], dep[mxN], par[mxN], pos[mxN];
    vector<int> adj[mxN];
    ll t[mxN];
    HLD() {}
    void init(vector<pl> a[]) {
        for (int i=1; i<=n; ++i) {
            for (pl j:a[i])
                adj[i].push_back(j.first);
        }
        dfs(); dfs2();
    }
    void tupd(int i, ll x) {
        for (++i; i<mxN; i+=i&-i)
            t[i]+=x;
    }
    void tupd(int l, int r, int x) {
        tupd(l, x);
        tupd(r+1, -x);
    }
    void upd(int a, int b, ll x) {
        for (; head[a]^head[b]; b=par[head[b]]) {
            if (dep[head[a]]>dep[head[b]])
                swap(a, b);
            tupd(pos[head[b]], pos[b], x);
        }
        if (dep[a]>dep[b])
            swap(a, b);
        tupd(pos[a], pos[b], x);
    }
    ll query(int i) {
        ll ret=0;
        for (++i; i; i-=i&-i)
            ret+=t[i];
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
} hld;
struct BIT {
    ll bit[mxN];
    void upd(int i, ll x) {
        for (++i; i<mxN; i+=i&-i)
            bit[i]+=x;
    }
    ll query(int i) {
        ll ret=0;
        for (++i; i; i-=i&-i)
            ret+=bit[i];
        return ret;
    }
    ll query(int l, int r) {
        return query(r)-query(l);
    }
} tree;

void dfs(int v=1, int p=0, int d=0) {
    parents.push_back(v);
    //binsearch for ancestor + update hld
    int lo=0, hi=d;
    while (lo<hi) {
        int m=lo+hi>>1;
        if (tree.query(m, d)<=mx)
            hi=m;
        else
            lo=m+1;
    }
    hld.upd(v, parents[lo], 1);
    for (pl nxt:adj[v]) {
        ll u=nxt.first, dst=nxt.second;
        if (u==p)
            continue;
        tree.upd(d+1, dst);
        dfs(u, v, d+1);
        tree.upd(d+1, -dst);
    }
    parents.pop_back();
}

int main() {
    ifstream cin("runaway.in");
    ofstream cout("runaway.out");
    cin >> n >> mx;
    for (int i=2; i<=n; ++i) {
        ll x, l;
        cin >> x >> l;
        adj[i].emplace_back(x, l);
        adj[x].emplace_back(i, l);
    }
    hld.init(adj);
    dfs();
    for (int i=1; i<=n; ++i)
        cout << hld.query(hld.pos[i]) << '\n';
}

