#include <bits/stdc++.h>
#define pb push_back
using namespace std;
using ll=long long;

const int mxN=1e5+1;
int n, q, t, in[mxN], out[mxN], dep[mxN];
ll bit[2*mxN];
vector<int> adj[mxN];

void upd(int i, ll x) {
    for (++i; i<=2*n; i+=i&-i)
        bit[i]+=x;
}
ll query(int i) {
    ll ans=0;
    for (++i; i>0; i-=i&-i)
        ans+=bit[i];
    return ans;
}
ll query(int l, int r) {
    return query(r)-query(l-1);
}

void dfs(int v=1, int p=0, int d=0) {
    in[v]=t++, dep[v]=d;
    for (int u:adj[v])
        if (u^p)
            dfs(u, v, d+1);
    out[v]=t++;
}

void reset() {
    for (int i=1; i<=n; ++i)
        adj[i].clear();
    memset(bit, 0, sizeof(bit));
    t=0;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int tt; cin >> tt;
    while (tt--) {
        reset();
        cin >> n >> q;
        for (int i=1; i<n; ++i) {
            int a, b;
            cin >> a >> b;
            adj[a].pb(b);
            adj[b].pb(a);
        }
        dfs();
        while (q--) {
            int a, b, x;
            cin >> a >> b >> x;
            if (x) {
                upd(in[a], x);
                upd(in[b], -x);
            }
            else {
                if (dep[a]<dep[b])
                    swap(a, b);
                cout << abs(query(in[a], out[a])) << '\n';
            }
        }
    }
}

