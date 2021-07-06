#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 69;
int n, m, grp[N];
vector<int> adj[N], ans;

void solve() {
    cin >> n >> m;

    for (int i = 1; i <= n; ++i)
        adj[i].clear();

    while (m--) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    ans.clear();
    memset(grp, 0, (n + 1) * sizeof(int));
    for (int v = 1; v <= n; ++v) {
        if (grp[v] < 2) {
            for (int u : adj[v])
                grp[u] = max(grp[u], grp[v] + 1);
        }
        else
            ans.push_back(v);
    }

    int sz = ans.size();
    cout << sz << '\n';
    for (int i = 0; i < sz; ++i)
        cout << ans[i] << " \n"[i == sz - 1];
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t; cin >> t;
    while (t--)
        solve();
}
