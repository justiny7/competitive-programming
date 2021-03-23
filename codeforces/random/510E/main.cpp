#include <bits/stdc++.h>
using namespace std;

const int mxN = 250, src = 245, snk = 246;
int n, cnt, a[mxN];
bool vis[mxN];

//{{{ Dinic's
template<class T> struct Edge {
    T v, flow, c, rev;
};
template<class T> struct Dinic {
    int lvl[mxN], start[mxN];
    vector<Edge<T>> adj[mxN];

    Dinic() {}
    void add(int u, int v, T cap) {
        Edge<T> a{v, 0, cap, (int)adj[v].size()};
        Edge<T> b{u, 0, 0, (int)adj[u].size()};
        adj[u].push_back(a);
        adj[v].push_back(b);
    }
    bool bfs() {
        memset(lvl, -1, sizeof(lvl));
        lvl[src] = 0;
        queue<int> q;
        q.push(src);
        while (q.size()) {
            int t = q.front(); q.pop();
            for (Edge<T> &u : adj[t])
                if (lvl[u.v] < 0 && u.flow < u.c)
                    lvl[u.v] = lvl[t] + 1, q.push(u.v);
        }
        return (~lvl[snk]);
    }
    T go(int cur, T flo) {
        if (cur == snk)
            return flo;
        while (start[cur] < adj[cur].size()) {
            Edge<T> &e = adj[cur][start[cur]];
            if (lvl[e.v] == lvl[cur] + 1 && e.flow < e.c) {
                T tflo = go(e.v, min(flo, e.c - e.flow));
                if (tflo > 0) {
                    e.flow += tflo, adj[e.v][e.rev].flow -= tflo;
                    return tflo;
                }
            }
            ++start[cur];
        }
        return 0;
    }
    T dinic() {
        T ret = 0;
        while (bfs()) {
            memset(start, 0, sizeof(start));
            while (T f = go(src, 1e9))
                ret += f;
        }
        return ret;
    }
};
//}}}

bool is_prime(int x) {
    if (x == 2 || x == 3 || x == 5 || x == 7)
        return 1;
    if ((x & 1) ^ 1)
        return 0;
    for (int i = 3; i * i <= x; i += 2)
        if (x % i == 0)
            return 0;
    return 1;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    Dinic<int> g;
    for (int i = 1; i <= n; ++i) {
        if (a[i] & 1) {
            g.add(src, i, 2);
            ++cnt;
            for (int j = 1; j <= n; ++j)
                if (is_prime(a[i] + a[j]))
                    g.add(i, j, 1);
        }
        else
            g.add(i, snk, 2);
    }
    if (cnt * 2 != n || g.dinic() != cnt * 2) {
        cout << "Impossible\n";
        return 0;
    }
    vector<vector<int>> ans;
    for (int i = 1; i <= n; ++i) {
        if (vis[i])
            continue;
        vector<int> here = {i};
        int v = i;
        vis[v] = 1;
        while (1) {
            bool f = 0;
            for (auto e : g.adj[v]) {
                if (!vis[e.v] && ((a[v] & 1) ? e.flow == 1 : e.flow == -1)) {
                    vis[v = e.v] = 1;
                    here.push_back(v);
                    f = 1;
                    break;
                }
            }
            if (!f)
                break;
        }
        ans.push_back(here);
    }
    cout << ans.size() << '\n';
    for (auto v : ans) {
        cout << v.size();
        for (int i : v)
            cout << " " << i;
        cout << '\n';
    }
}
