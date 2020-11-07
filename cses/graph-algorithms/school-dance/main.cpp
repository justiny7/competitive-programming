#include <bits/stdc++.h>
#define pb push_back
using namespace std;
using ll=long long;
//Maximum matching
const int mxN=1010;
int n, m, k;

struct Edge {
    ll v, flow, c, rev;
};

struct Graph {
    ll lvl[mxN], start[mxN];
    vector<Edge> adj[mxN];

    void add(int u, int v, ll cap) {
        Edge a {v, 0, cap, (int)adj[v].size()};
        Edge b {u, 0, 0, (int)adj[u].size()};
        adj[u].pb(a);
        adj[v].pb(b);
    }

    bool bfs(int source=0, int sink=n+m+1) {
        fill(lvl, lvl+sink+1, -1);
        lvl[source]=0;
        queue<int> q;
        q.push(source);
        while (!q.empty()) {
            int t=q.front(); q.pop();
            for (auto& u:adj[t])
                if (lvl[u.v]<0 && u.flow<u.c) {
                    lvl[u.v]=lvl[t]+1;
                    q.push(u.v);
                }
        }
        return (lvl[sink]>=0);
    }

    ll send(int cur, ll flo, int sink=n+m+1) {
        if (cur==sink)
            return flo;
        while (start[cur]<adj[cur].size()) {
            Edge &e=adj[cur][start[cur]];
            if (lvl[e.v]==lvl[cur]+1 && e.flow<e.c) {
                ll cmin=min(flo, e.c-e.flow), tflo=send(e.v, cmin);
                if (tflo>0) {
                    e.flow+=tflo;
                    adj[e.v][e.rev].flow-=tflo;
                    return tflo;
                }
            }
            ++start[cur];
        }
        return 0;
    }

    ll dinic() {
        ll tot=0;
        while (bfs()) {
            fill (start, start+n+m+2, 0);
            while (ll f=send(0, 1e18))
                tot+=f;
        }
        return tot;
    }
};

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> k;
    Graph g;
    for (int i=1; i<=n; ++i)
        g.add(0, i, 1);
    for (int i=n+1; i<=n+m; ++i)
        g.add(i, n+m+1, 1);
    while (k--) {
        int a, b;
        cin >> a >> b;
        g.add(a, b+n, 1);
    }
    ll mflo=g.dinic();
    cout << mflo << '\n';
    for (auto& e1:g.adj[0])
        if (e1.flow>0)
            for (auto& e2:g.adj[e1.v])
                if (e2.flow>0)
                    cout << e1.v << " " << e2.v-n << '\n';
}

