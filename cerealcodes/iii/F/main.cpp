#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int n, order[N];
vector<int> adj[N], tadj[N], res;
bool merged[N];

int dsu[N];
int find(int v) {
    return (v == dsu[v] ? v : dsu[v] = find(dsu[v]));
}
bool merge(int u, int v) {
    u = find(u), v = find(v);
    if (u == v) {
        return false;
    }
    dsu[u] = v;
    return true;
}

void dfs(int v) {
    res.push_back(v);
    for (int u : tadj[v]) {
        dfs(u);
    }
}

void solve() {
    cin >> n;

    res.clear();
    for (int i = 1; i <= n; i++) {
        adj[i].clear();
        tadj[i].clear();
        dsu[i] = i;
        merged[i] = false;
    }

    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 1; i <= n; i++) {
        cin >> order[i];
    }

    set<int> cur;
    for (int i = 1; i < n; i++) {
        int v = order[i], c = 0;
        for (int u : adj[v]) {
            c += !cur.count(u);
        }

        if (c == 1) {
            cur.insert(v);
        } else {
            break;
        }
    }

    if (cur.size() == n - 1) {
        cout << "1\n";
        for (int i = 1; i <= n; i++) {
            cout << order[i] << " \n"[i == n];
        }
        return;
    }

    for (int i = 1; i <= n; i++) {
        int v = order[i];
        merged[v] = true;
        for (int u : adj[v]) {
            if (merged[u]) {
                tadj[v].push_back(find(u));
                merge(u, v);
            }
        }
    }

    cout << "2\n";
    dfs(order[n]);
    for (int i = 0; i < n; i++) {
        cout << res[i] << " \n"[i == n - 1];
    }
    for (int i = 1; i <= n; i++) {
        cout << order[i] << " \n"[i == n];
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
