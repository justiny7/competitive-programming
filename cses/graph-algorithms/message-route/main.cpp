#include <bits/stdc++.h>
#define pb push_back
using namespace std;

int n, m, vis[100001];
vector<int> adj[100001], ans;

void rev(int cur) {
    ans.pb(cur);
    if (cur==1)
        return;
    for (int u : adj[cur])
        if (vis[u]==vis[cur]-1) {
            rev(u);
            return;
        }
}

int main(void) {
    cin >> n >> m;
    for (int i=0; i<m; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    queue<pair<int, int>> q;
    q.push({1, 1});
    vis[1]=1;
    while (!q.empty()) {
        int t=q.front().first, d=q.front().second;
        q.pop();
        if (t==n) {
            rev(n);
            cout << ans.size() << '\n';
            for (int i=ans.size()-1; i>=0; --i) {
                if (i<ans.size()-1)
                    cout << " ";
                cout << ans[i];
            }
            cout << '\n';
            return 0;
        }
        for (int u : adj[t])
            if (!vis[u]) {
                q.push({u, d+1});
                vis[u]=d+1;
            }
    }
    cout << "IMPOSSIBLE\n";
}
