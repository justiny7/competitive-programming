/*
ID: justiny7
LANG: C++
TASK: milk6
*/

//This should just be the min cut problem - use Dinic's algorithm (it's faster than Ford-Fulkerson) - the Dinic's credits go to GeeksForGeeks lol
//YESSSS finally (15 submissions) - Timestamp: 1:31am
#include <bits/stdc++.h>
#define pb push_back
using namespace std;

ifstream fin("milk6.in");
ofstream fout("milk6.out");

int n, m, mflo, minE = 2e9, beg[1001], en[1001], cst[1001];
vector<int> cands;
string minP = "0";

struct Edge {
    int v, flow, c, rev, ind;
};

struct Graph {
    int lvl[33], start[33];
    vector<Edge> adj[33];

    void adde(int u, int v, int cap, int i) {
        Edge a {v, 0, cap, (int)adj[v].size(), i};
        Edge b {u, 0, 0, (int)adj[u].size(), i};
        adj[u].pb(a);
        adj[v].pb(b);
    }

    bool bfs() {
        fill(lvl+1, lvl+n+1, -1);
        lvl[1] = 0;
        queue<int> q;
        q.push(1);
        while (!q.empty()) {
            int t = q.front();
            q.pop();
            for (auto neigh : adj[t])
                if (lvl[neigh.v] < 0 && neigh.flow < neigh.c) {
                    lvl[neigh.v] = lvl[t]+1;
                    q.push(neigh.v);
                }
        }
        return (lvl[n] >= 0);
    }

    bool bfs2() { //only diff is making sure flow > 0 (the path actually exists)
        fill(lvl+1, lvl+n+1, -1);
        lvl[1] = 0;
        queue<int> q;
        q.push(1);
        while (!q.empty()) {
            int t = q.front();
            q.pop();
            for (auto neigh : adj[t])
                if (lvl[neigh.v] < 0 && neigh.flow < neigh.c && neigh.flow > 0) {
                    lvl[neigh.v] = lvl[t]+1;
                    q.push(neigh.v);
                }
        }
        return (lvl[n] >= 0);
    }

    int sendf(int cur, int flo) {
        if (cur == n)
            return flo;
        while (start[cur] < adj[cur].size()) {
            Edge &e = adj[cur][start[cur]];
            if (lvl[e.v] == lvl[cur]+1 && e.flow < e.c) {
                int curflo = min(flo, e.c-e.flow);
                int tflo = sendf(e.v, curflo);
                if (tflo > 0) {
                    e.flow += tflo;
                    adj[e.v][e.rev].flow -= tflo;
                    return tflo;
                }
            }
            start[cur]++;
        }
        return 0; //should never get here (hopefully)
    }

    int dinic() {
        int tot = 0;
        while (bfs()) {
            fill(start, start+n+1, 0);
            while (int f = sendf(1, 2e9))
                tot += f;
        }
        return tot;
    }
};

int main(void) {
    fin >> n >> m;
    Graph g;
    for (int i = 1; i <= m; i++) {
        fin >> beg[i] >> en[i] >> cst[i];
        g.adde(beg[i], en[i], cst[i], i);
    }
    mflo = g.dinic();
    int csum = 0;
    for (int i = 1; i <= m; i++) {
        Graph gg;
        for (int j = 1; j <= m; j++)
            if (j != i)
                gg.adde(beg[j], en[j], cst[j], j);
        int nflo = gg.dinic();
        if (nflo < mflo) {
            cands.pb(i);
            csum += cst[i];
        }
    }
    if (csum == mflo) {
        fout << mflo << " " << cands.size() << '\n';
        for (int a : cands)
            fout << a << '\n';
        return 0;
    }
    stack<pair<int, pair<string, int>>> st; //dfs for answer
    st.push({0, {"", 0}});
    while (!st.empty()) {
        string path = st.top().second.first;
        int t = st.top().first, len = path.length(), o = st.top().second.second;
        st.pop();
        //cout << t << " " << path << '\n';
        if (o > minE)
            continue;
        if (len == cands.size()) {
            if (t != mflo)
                continue;
            Graph gg;
            for (int i = 0; i < len; i++)
                if (path[i] == '1')
                    gg.adde(beg[cands[i]], en[cands[i]], cst[cands[i]], cands[i]);
            if ((o == minE && path < minP) || gg.bfs2())
                continue;
            minE = o;
            minP = path;
            continue;
        }
        st.push({t, {path+"0", o}});
        if (t+cst[cands[len]] <= mflo)
            st.push({t+cst[cands[len]], {path+"1", o+1}});
    }
    fout << mflo << " " << minE << '\n';
    for (int i = 0; i < cands.size(); i++)
        if (minP[i] == '1')
            fout << cands[i] << '\n';
    return 0;
}
