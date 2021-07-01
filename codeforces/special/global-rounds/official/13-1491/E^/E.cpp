#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 69;
int n, sz[N], s[N], par[N];
vector<int> adj[N], cur;

void dfs(int v, int p = 0) {
    sz[v] = 1;
    par[v] = p;
    cur.push_back(v);

    for (int u : adj[v]) {
        if (u != p) {
            dfs(u, v);
            sz[v] += sz[u];
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> n;
    for (int i = 1, u, v; i < n; ++i) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int f1 = 1, f2 = 2;
    bool have = (n == 1 || n == 2);
    s[2] = 1;
    while (f1 + f2 < N) {
        int nxt = f1 + f2;

        s[nxt] = f2;
        f1 = f2, f2 = nxt;
        have |= (n == nxt);
    }

    if (!have) {
        cout << "NO\n";
        return 0;
    }

    vector<int> todo = {1}, nxt;
    while (todo.size()) {
        for (int v : todo) {
            cur.clear();
            dfs(v);

            if (sz[v] > 1) {
                bool f = 0;
                for (int u : cur) {
                    if (sz[u] == s[sz[v]] || sz[u] == sz[v] - s[sz[v]]) {
                        int p = par[u];
                        nxt.push_back(u);
                        nxt.push_back(p);

                        adj[u].erase(find(adj[u].begin(), adj[u].end(), p));
                        adj[p].erase(find(adj[p].begin(), adj[p].end(), u));

                        f = 1;
                        break;
                    }
                }

                if (!f) {
                    cout << "NO\n";
                    return 0;
                }
            }
        }

        todo = nxt;
        nxt.clear();
    }

    cout << "YES\n";
}
