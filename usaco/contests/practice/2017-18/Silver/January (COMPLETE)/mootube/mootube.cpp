//USACO Silver January 2018 Problem 3

//In the end the only optimization was not bfs-ing from every node smh
//Bruh just realized that we never wanna travel on paths less than indicated max - too lazy to implement
#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
using namespace std;
typedef pair<int, int> pii;

ifstream fin("mootube.in");
ofstream fout("mootube.out");

int n, q, rel[5001][5001];
vector<int> adj[5001];
vector<pii> queries;
set<int> nodes;

void print() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++)
            cout << rel[i][j] << " ";
        cout << '\n';
    }
}

int main(void) {
    fin >> n >> q;
    for (int i = 1; i < n; i++) {
        int a, b, c;
        fin >> a >> b >> c;
        adj[a].pb(b);
        adj[b].pb(a);
        rel[a][b] = rel[b][a] = c;
    }
    for (int i = 0; i < q; i++) {
        int a, b;
        fin >> a >> b;
        queries.pb({a, b});
        nodes.insert(b);
    }
    for (auto it = nodes.begin(); it != nodes.end(); it++) {
        bool vis[5001];
        fill(vis+1, vis+n+1, 0);
        int i = *it;
        queue<pii> q;
        q.push({i, INT_MAX});
        vis[i] = 1;
        while (!q.empty()) {
            int t = q.front().fi, cm = q.front().se; //curmin
            q.pop();
            if (t != i && rel[t][i] == 0)
                rel[i][t] = rel[t][i] = cm;
            for (int u : adj[t])
                if (!vis[u]) {
                    q.push({u, min(cm, rel[t][u])});
                    vis[u] = 1;
                }
        }
    }
    for (pii qu : queries) {
        int curcnt = 0;
        for (int i = 1; i <= n; i++)
            if (rel[qu.se][i] >= qu.fi)
                curcnt++;
        fout << curcnt << '\n';
    }
    return 0;
}

