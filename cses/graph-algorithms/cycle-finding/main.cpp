#include <bits/stdc++.h>
using namespace std;
using ll=long long;

struct Edge {
    ll v, u, w;
};

const ll BIG=1e18;
int n, m;
vector<Edge> edges;

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    while (m--) {
        ll a, b, c;
        cin >> a >> b >> c;
        edges.push_back(Edge{a, b, c});
    }
    vector<ll> dist(n+1), par(n+1, -1);
    ll x;
    for (int i=0; i<n; ++i) {
        x=-1;
        for (Edge e:edges)
            if (dist[e.v]+e.w<dist[e.u]) {
                dist[e.u]=max(-BIG, dist[e.v]+e.w);
                par[e.u]=e.v;
                x=e.u;
            }
    }
    if (x==-1) {
        cout << "NO\n";
        return 0;
    }
    cout << "YES\n";
    for (int i=0; i<n; ++i, x=par[x]);
    vector<ll> ans;
    for (int v=x;; v=par[v]) {
        ans.push_back(v);
        if (v==x && ans.size()>1)
            break;
    }
    for (int i=ans.size()-1; i>=0; --i) {
        cout << ans[i];
        if (i)
            cout << " ";
    }
    cout << '\n';
}
