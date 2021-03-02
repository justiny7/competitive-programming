#include <bits/stdc++.h>
using namespace std;

const int mxN=1e5+1;
int n, m, vis[mxN];
vector<int> adj[mxN];
bool vis2[2][mxN];

//if graph is bipartite, then n-1 always works
//otherwise, more complicated :(
//all self-loops in G must also be in G' - nevermind

//{{{ Bipartite 
bool bipartite() {
    queue<int> q;
    memset(vis, -1, sizeof(vis));
    q.push(1);
    vis[1]=0;
    while (q.size()) {
        int v=q.front(); q.pop();
        for (int u:adj[v]) {
            if (vis[u]==vis[v])
                return 0;
            if (vis[u]<0) {
                vis[u]=vis[v]^1;
                q.push(u);
            }
        }
    }
    return 1;
}
//}}}

vector<pair<int, int>> masks[6];
void get_masks() {
    for (int t=1; t<=5; ++t) {
        int mx=(t*t+t)/2;
        for (int i=0; i<(1<<mx); ++i)
            if (__builtin_popcount(i)>=n-1)
                masks[t].emplace_back(__builtin_popcount(i), i);
        sort(masks[t].begin(), masks[t].end());
    }
}
void solve() {
    cin >> n >> m;
    for (int i=1; i<=n; ++i)
        adj[i].clear();
    if (n<=5) {
        vector<int> self;
        vector<pair<int, int>> edges;
        for (int i=0; i<m; ++i) {
            int a, b;
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
            //if (a==b)
                //self.push_back(a);
            //else
                //edges.emplace_back(a, b);
        }
        int orig[2][6];
        memset(orig, -1, sizeof(orig));
        {
            //for (int j:self)
                //adj[j].push_back(j);
            queue<pair<int, int>> q;
            q.emplace(1, 0);
            orig[0][1]=0;
            while (q.size()) {
                auto [v, d]=q.front(); q.pop();
                int nd=d+1;
                for (int u:adj[v]) {
                    if (orig[nd&1][u]<0) {
                        orig[nd&1][u]=nd;
                        q.emplace(u, nd);
                    }
                }
            }
            //for (int t=0; t<2; ++t)
                //for (int j=1; j<=n; ++j)
                    //cout << orig[t][j] << " \n"[j==n];
        }
        for (int i=1; i<=n; ++i)
            for (int j=i; j<=n; ++j)
                edges.emplace_back(i, j);
        int sz=edges.size(), here[2][6];
        for (auto [cnt, i]:masks[n]) {
            memset(here, -1, sizeof(here));
            for (int j=1; j<=n; ++j)
                adj[j].clear();
            //for (int j:self)
                //adj[j].push_back(j);
            for (int j=0; j<sz; ++j) {
                if (i&(1<<j)) {
                    auto [a, b]=edges[j];
                    adj[a].push_back(b);
                    adj[b].push_back(a);
                }
            }
            queue<pair<int, int>> q;
            q.emplace(1, 0);
            here[0][1]=0;
            while (q.size()) {
                auto [v, d]=q.front(); q.pop();
                int nd=d+1;
                for (int u:adj[v]) {
                    if (here[nd&1][u]<0) {
                        here[nd&1][u]=nd;
                        q.emplace(u, nd);
                    }
                }
            }
            bool f=1;
            for (int t=0; t<2; ++t) {
                for (int j=1; j<=n; ++j) {
                    if (here[t][j]^orig[t][j]) {
                        f=0;
                        break;
                    }
                }
                if (!f)
                    break;
            }
            if (f) {
                //cout << bitset<5>(i) << '\n';
                //cout << "edges used:\n";
                //for (int j=0; j<sz; ++j)
                    //if (i&(1<<j))
                        //cout << edges[j].first << " " << edges[j].second << '\n';
                cout << cnt << '\n';
                return;
            }
        }
    }
    for (int i=0; i<m; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    if (bipartite()) {
        cout << n-1 << '\n';
        return;
    }
    else if (n==m)
        cout << m << '\n';
    else {
        memset(vis2, 0, sizeof(vis2));
        queue<pair<int, int>> q;
        set<pair<int, int>> have;
        q.emplace(1, 0);
        vis2[0][1]=1;
        while (q.size()) {
            auto [v, d]=q.front(); q.pop();
            int nd=d+1;
            for (int u:adj[v]) {
                if (!vis2[nd&1][u]) {
                    vis2[nd&1][u]=1;
                    have.emplace(min(u, v), max(u, v));
                    q.emplace(u, nd);
                }
            }
        }
        cout << have.size() << '\n';
    }
}

int main() {
    get_masks();
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--)
        solve();
}

