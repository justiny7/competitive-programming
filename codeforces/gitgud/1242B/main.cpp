#include <bits/stdc++.h>
using namespace std;

const int mxN=1e5+1;
int n, m, ans;
set<int> adj[mxN], all;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    for (int i=1; i<=n; ++i)
        all.insert(i);
    while (m--) {
        int a, b;
        cin >> a >> b;
        adj[a].insert(b);
        adj[b].insert(a);
    }
    for (int i=1; i<=n; ++i) {
        if (!all.count(i))
            continue;
        ++ans;
        queue<int> q;
        q.push(i);
        all.erase(i);
        while (q.size()) {
            int v=q.front(); q.pop();
            vector<int> nxt;
            for (int u:all)
                if (!adj[v].count(u))
                    nxt.push_back(u), q.push(u);
            for (int u:nxt)
                all.erase(u);
        }
    }
    cout << ans-1 << '\n';
}

