#include <bits/stdc++.h>
using namespace std;
using ll=long long;

const int mxN=2e5+1;
int n, q, t, c[mxN], a[mxN<<1], in[mxN], out[mxN];
ll bit[mxN<<1];
vector<int> adj[mxN];

void upd(int i, ll x) {
    for (++i; i<=(n<<1); i+=i&-i)
        bit[i]+=x;
}
ll query(int i) {
    ll ans=0;
    for (++i; i>0; i-=i&-i)
        ans+=bit[i];
    return ans;
}

void dfs(int v=1, int p=0) {
    in[v]=t++;
    for (int u:adj[v])
        if (u^p)
            dfs(u, v);
    out[v]=t++;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> q;
    for (int i=1; i<=n; ++i)
        cin >> c[i];
    for (int i=1; i<n; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs();
    for (int i=1; i<=n; ++i) {
        upd(in[i], c[i]);
        upd(out[i], -c[i]);
    }
    while (q--) {
        int t; cin >> t;
        if (t==1) {
            int v, x;
            cin >> v >> x;
            ll dif=x-c[v];
            upd(in[v], dif);
            upd(out[v], -dif);
            c[v]=x;
        }
        else {
            int v; cin >> v;
            cout << query(out[v]-1) << '\n';
        }
    }
}

