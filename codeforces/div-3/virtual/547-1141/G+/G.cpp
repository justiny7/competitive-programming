#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 69;
int n, k, ans, deg[N], res[N];
vector<array<int, 2>> adj[N];

void dfs(int v = 1, int p = 0, int col = 0) {
    int cur = 1;
    for (auto [u, i] : adj[v]) {
        if (u == p)
            continue;

        if (cur == col) {
            col = 0;
            cur = cur % ans + 1;
        }

        res[i] = cur;
        dfs(u, v, cur);
        cur = cur % ans + 1;
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> n >> k;

    for (int i = 1, u, v; i < n; ++i) {
        cin >> u >> v;
        adj[u].push_back({v, i});
        adj[v].push_back({u, i});
        ++deg[u], ++deg[v];
    }

    map<int, int> cnt;
    for (int i = 1; i <= n; ++i)
        // cout << "> " << i << " " << deg[i] << '\n',
        ++cnt[deg[i]];

    int take = 0;
    for (auto [x, c] : cnt) {
        take += c;
        ans = x;
        if (take >= n - k)
            break;
    }

    cout << ans << '\n';

    dfs();
    for (int i = 1; i < n; ++i)
        cout << res[i] << " \n"[i == n - 1];
}

