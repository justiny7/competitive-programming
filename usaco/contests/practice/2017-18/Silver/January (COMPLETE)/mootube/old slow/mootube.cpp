//USACO Silver January 2018 Problem 3

//I'm gonna create a new file
#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
using namespace std;
typedef pair<int, int> pii;

ifstream fin("mootube.in");
ofstream fout("mootube.out");

int n, q, rel[5001][5001], alr[5001];
vector<int> adj[5001];
vector<pii> queries;
bool vis[5001];

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
        alr[a]++;
        alr[b]++;
    }
    for (int i = 0; i < q; i++) {
        int a, b;
        fin >> a >> b;
        queries.pb({a, b});
    }
    int curcount = (n-1)*2;
    for (int i = 1; i <= n; i++) { //I doubt this will run in time but it's just a first attempt
        if (alr[i] == n)
            continue;
        fill(vis+1, vis+n+1, false); //Wait it ran in time - just some small fixes - nooo timeout on one case - 1 more optimization
        queue<pii> q;
        q.push({i, INT_MAX});
        while (!q.empty()) {
            int t = q.front().fi, curmin = q.front().se;
            q.pop();
            if (t != i && rel[t][i] == 0) {
                rel[i][t] = rel[t][i] = curmin;
                alr[i]++;
                alr[t]++;
                curcount += 2;
            }
            if (curcount == n*(n-1) || alr[i] == n)
                break;
            for (int u : adj[t]) {
                if (!vis[u]) {
                    vis[u] = true;
                    q.push({u, min(curmin, rel[t][u])});
                }
            }
        }
        if (curcount == n*(n-1))
            break;
    }
    //print();
    for (pii qu : queries) {
        int curcnt = 0;
        for (int i = 1; i <= n; i++)
            if (rel[qu.se][i] >= qu.fi)
                curcnt++;
        fout << curcnt << '\n';
    }
    return 0;
}
