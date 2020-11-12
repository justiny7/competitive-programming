#include <bits/stdc++.h>
using namespace std;

const int mxN=3e2+5, SRC=220, SNK=221; //220=supersource, 221=supersink
int n, m, a[mxN], b[mxN], atot, btot, ans[mxN][mxN];

//Dinic's
struct Edge {
    int v, flow, c, rev;
};
struct Graph {
    int lvl[mxN], st[mxN];
    vector<Edge> adj[mxN];

    void add(int u, int v, int cap) {
        Edge a{v, 0, cap, (int)adj[v].size()};
        Edge b{u, 0, 0, (int)adj[u].size()};
        adj[u].push_back(a);
        adj[v].push_back(b);
    }
    bool bfs() {
        memset(lvl, -1, sizeof(lvl));
        lvl[SRC]=0;
        queue<int> q;
        q.push(SRC);
        while (q.size()) {
            int t=q.front(); q.pop();
            for (auto &u:adj[t])
                if (lvl[u.v]<0 && u.flow<u.c)
                    lvl[u.v]=lvl[t]+1, q.push(u.v);
        }
        return (~lvl[SNK]);
    }
    int send(int cur, int flo) {
        if (cur==SNK)
            return flo;
        while (st[cur]<adj[cur].size()) {
            Edge &e=adj[cur][st[cur]];
            if (lvl[e.v]==lvl[cur]+1 && e.flow<e.c) {
                int tflo=send(e.v, min(flo, e.c-e.flow));
                if (tflo>0) {
                    e.flow+=tflo;
                    adj[e.v][e.rev].flow-=tflo;
                    return tflo;
                }
            }
            ++st[cur];
        }
        return 0;
    }
    int dinic() {
        int tot=0;
        while (bfs()) {
            memset(st, 0, sizeof(st));
            while (int f=send(SRC, 1e9))
                tot+=f;
        }
        return tot;
    }
};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    for (int i=1; i<=n; ++i)
        cin >> a[i], atot+=a[i];
    for (int i=1; i<=n; ++i)
        cin >> b[i], btot+=b[i];
    Graph g;
    for (int i=1; i<=n; ++i) {
        g.add(SRC, i, a[i]);
        g.add(i+n, SNK, b[i]);
        g.add(i, i+n, 1e8);
    }
    while (m--) {
        int a, b;
        cin >> a >> b;
        g.add(a, b+n, 1e8);
        g.add(b, a+n, 1e8);
    }
    int mflo=g.dinic();
    if (mflo==atot && mflo==btot) {
        cout << "YES\n";
        for (int i=1; i<=n; ++i)
            for (Edge e:g.adj[i])
                if (e.v^SRC)
                    ans[i][e.v-n]+=e.flow;
        for (int i=1; i<=n; ++i)
            for (int j=1; j<=n; ++j)
                cout << ans[i][j] << " \n"[j==n];
    }
    else
        cout << "NO\n";
}

