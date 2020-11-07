#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
using pii=pair<int, int>;

const int mxN=1e5+1;
int n;
struct edge {
    int v, u, id;
};
vector<edge> edges;
vector<int> pth;
map<int, vector<int>> adj;
map<int, int> lst, vis;
map<int, pii> ans;

void dfs(int v, int st) {
    pth.push_back(v);
    vis[v]=st;
    for (int u:adj[v])
        if (!vis.count(u))
            dfs(u, st);
}

void solve() {
    cin >> n;
    edges.clear(); edges.resize(n);
    set<int> s;
    for (int i=0; i<n; ++i) {
        cin >> edges[i].v >> edges[i].u, edges[i].id=i+1;
        s.insert(edges[i].v); s.insert(edges[i].u);
    }
    adj.clear();
    for (edge e:edges) {
        adj[e.v].push_back(e.u);
        adj[e.u].push_back(e.v);
    }
    lst.clear(); vis.clear();
    vector<int> cmp;
    for (int i:s)
        if (!vis.count(i))
            pth.clear(), dfs(i, i), lst[i]=pth.back(), cmp.push_back(i);
    ans.clear();
    for (edge e:edges) {
        if (e.v==lst[vis[e.v]])
            ans[vis[e.v]]=pii(e.id, e.v);
        else if (e.u==lst[vis[e.u]])
            ans[vis[e.u]]=pii(e.id, e.u);
    }
    cout << cmp.size()-1 << '\n';
    for (int i=1; i<cmp.size(); ++i)
        cout << ans[cmp[i]].fi << " " << ans[cmp[i]].se << " " << cmp[0] << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--)
        solve();
}

