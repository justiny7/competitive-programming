#include <bits/stdc++.h>
#define pb push_back
using namespace std;
using pii=pair<int, int>;

const int mxN=1e3+1;
int n, k1, k2;
vector<int> adj[mxN];
set<int> x, y;

int bfs(int st) {
    queue<pii> q;
    q.push(pii(st, 0));
    while (q.size()) {
        int v, p;
        tie(v, p)=q.front(); q.pop();
        if (x.count(v))
            return v;
        for (int u:adj[v])
            if (u^p)
                q.push(pii(u, v));
    }
    return -1;
}
void solve() {
    cin >> n;
    for (int i=1; i<=n; ++i)
        adj[i].clear();
    x.clear(); y.clear();
    for (int i=1; i<n; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    cin >> k1;
    for (int i=0; i<k1; ++i) {
        int a; cin >> a;
        x.insert(a);
    }
    cin >> k2;
    for (int i=0; i<k2; ++i) {
        int a; cin >> a;
        y.insert(a);
    }
    cout << "B " << *y.begin() << endl;
    int ret, go; cin >> ret;
    go=bfs(ret);
    cout << "A " << go << endl;
    cin >> ret;
    cout << "C " << (y.count(ret)?go:-1) << endl;
}

int main() {
    int t; cin >> t;
    while (t--)
        solve();
}

