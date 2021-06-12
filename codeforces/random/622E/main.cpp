#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 69;
int n, ans;
vector<int> adj[N], dep;

void dfs(int v, int p, int d = 1) {
    if (adj[v].size() == 1)
        dep.push_back(d);

    for (int u : adj[v])
        if (u != p)
            dfs(u, v, d + 1);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> n;
    for (int i = 1, u, v; i < n; ++i) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int u : adj[1]) {
        dep.clear();
        dfs(u, 1);

        sort(dep.begin(), dep.end());
        int cur = dep[0];

        for (int i = 1; i < dep.size(); ++i)
            cur = max(cur + 1, dep[i]);

        ans = max(ans, cur);
    }

    cout << ans << '\n';
}
