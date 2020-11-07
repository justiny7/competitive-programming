#include <bits/stdc++.h>
#define pb push_back
using namespace std;
using ll=long long;
//Min cut
const int mxN=501;
int n, m;
set<pair<int, int>> ans;

struct Edge {
    ll v, flow, c, rev;
};

struct Graph {
    ll lvl[mxN], start[mxN];
    vector<Edge> adj[mxN];
    bool matr[mxN][mxN];

    void add(int u, int v, ll cap) {
        Edge a {v, 0, cap, (int)adj[v].size()};
        Edge b {u, 0, 0, (int)adj[u].size()};
        adj[u].pb(a);
        adj[v].pb(b);
        matr[u][v]=1;
    }

    bool bfs() {
        fill(lvl+1, lvl+n+1, -1);
        lvl[1]=0;
        queue<int> q;
        q.push(1);
        while (!q.empty()) {
            int t=q.front(); q.pop();
            for (auto& u:adj[t])
                if (lvl[u.v]<0 && u.flow<u.c) {
                    lvl[u.v]=lvl[t]+1;
                    q.push(u.v);
                }
        }
        return (lvl[n]>=0);
    }

    ll send(int cur, ll flo) {
        if (cur==n)
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
            fill (start+1, start+n+1, 0);
            while (ll f=send(1, 1e18))
                tot+=f;
        }
        return tot;
    }
};

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    Graph g;
    for (int i=1; i<=m; ++i) {
        int a, b;
        cin >> a >> b;
        g.add(a, b, 1);
        g.add(b, a, 1);
    }
    ll mflo=g.dinic();
    g.bfs();
    for (int i=1; i<=n; ++i)
        if (g.lvl[i]>=0)
            for (auto& e:g.adj[i])
                if (g.lvl[e.v]<0)
                    ans.insert({i, e.v});
    assert(ans.size()==mflo);
    cout << mflo << '\n';
    for (auto& p:ans)
        cout << p.first << " " << p.second << '\n';
}
