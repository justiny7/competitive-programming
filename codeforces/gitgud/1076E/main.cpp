#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
using namespace std;
using ll=long long;
using pii=pair<int, int>;

const int mxN=3e5+1;
int n, m;
ll bit[mxN], a[mxN];
vector<int> adj[mxN];
vector<pii> q[mxN];

void upd(int i, ll x) {
    for (++i; i<mxN; i+=i&-i)
        bit[i]+=x;
}
void upd(int l, int r, int x) {
    upd(l, x);
    upd(r+1, -x);
}
ll query(int i) {
    ll ans=0;
    for (++i; i>0; i-=i&-i)
        ans+=bit[i];
    return ans;
}

void dfs(int v=1, int p=0, int d=0) {
    for (pii p:q[v])
        upd(d, d+p.fi, p.se);
    a[v]=query(d);
    for (int u:adj[v])
        if (u^p)
            dfs(u, v, d+1);
    for (pii p:q[v])
        upd(d, d+p.fi, -p.se);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for (int i=1; i<n; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    cin >> m;
    while (m--) {
        int a, b, c;
        cin >> a >> b >> c;
        q[a].pb(pii(b, c));
    }
    dfs();
    for (int i=1; i<=n; ++i)
        cout << a[i] << (i<n?" ":"\n");
}

