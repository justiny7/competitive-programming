#include <bits/stdc++.h>
#define pb push_back
using namespace std;
//Yay first try
ifstream fin("piggyback.in");
ofstream fout("piggyback.out");

const int mxN=4e4+1;
int n, m, b, e, p, dist1[mxN], dist2[mxN], dist3[mxN], ans=INT_MAX;
vector<int> adj[mxN];

void bfs(int d[], int start) {
    fill(d+1, d+1+n, -1);
    queue<int> q;
    q.push(start);
    d[start]=0;
    while (!q.empty()) {
        int v=q.front();
        q.pop();
        for (int u:adj[v])
            if (d[u]<0) {
                d[u]=d[v]+1;
                q.push(u);
            }
    }
}

int main(void) {
    fin >> b >> e >> p >> n >> m;
    for (int i=0; i<m; ++i) {
        int a, b;
        fin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    bfs(dist1, 1);
    bfs(dist2, 2);
    bfs(dist3, n);
    for (int i=1; i<=n; ++i)
        ans=min(ans, b*dist1[i]+e*dist2[i]+p*dist3[i]);
    fout << ans << '\n';
}
