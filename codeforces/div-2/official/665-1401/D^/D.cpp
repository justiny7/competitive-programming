#include <bits/stdc++.h>
#define pb push_back
using namespace std;
using ll=long long;

const int mxN=1e5+1;
const ll M=1e9+7;
int n, m;
vector<ll> s, sz;
vector<vector<ll>> adj;

void dfs(int v=1, int p=0) {
    sz[v]=1;
    for (int u:adj[v])
        if (u^p) {
            dfs(u, v);
            sz[v]+=sz[u];
            s.pb(sz[u]*(n-sz[u]));
        }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        cin >> n;
        adj.clear(); s.clear(); sz.clear();
        adj.resize(n+1); sz.resize(n+1);
        for (int i=1; i<n; ++i) {
            int a, b;
            cin >> a >> b;
            adj[a].pb(b);
            adj[b].pb(a);
        }
        dfs();
        cin >> m;
        vector<ll> p(m);
        for (ll& i:p)
            cin >> i;
        while (p.size()<n-1)
            p.push_back(1);
        sort(p.begin(), p.end());
        while (p.size()>n-1) {
            int i=p.size()-2;
            p[i]=p[i]*p.back()%M;
            p.pop_back();
        }
        sort(s.begin(), s.end());
        ll ans=0;
        for (int i=0; i<n-1; ++i)
            ans=(ans+s[i]*p[i])%M;
        cout << (ans+M)%M << '\n';
    }
}

