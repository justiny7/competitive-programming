#include <bits/stdc++.h>
using namespace std;

const int N = 69;
int n, k, c[N];
vector<int> adj[N];

void solve() {
    cin >> n >> k;

    for (int i = 1; i <= n; ++i) {
        cin >> c[i];
        adj[i].clear();
    }

    for (int i = 1, u, v; i < n; ++i) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    if (k == 0) {
        cout << c[1] << '\n';
        return;
    }

}

int main() {
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int t;
    cin >> t;
    for (int tc = 1; tc <= t; ++tc) {
        cout << "Case #" << tc << ": ";
        solve();
    }
}

