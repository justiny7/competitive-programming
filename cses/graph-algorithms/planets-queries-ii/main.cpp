#include <bits/stdc++.h>
using namespace std;

// cc = # of cycles, pos = -2: not in cycle, else position in cycle, dist = distance from cycle
const int N = 2e5 + 69, L = 19;
int n, q, cc, to[N], pos[N], cyc[N], dist[N], sz[N], lift[N][L];
bool vis[N];

int jump(int v, int k) {
    for (int i = 0; i < L; ++i)
        if (k & (1 << i))
            v = lift[v][i];
    return v;
}

void same_cyc(int u, int v, int add = 0) {
    if (pos[v] > pos[u])
        cout << sz[cyc[u]] - pos[v] + pos[u] + add << '\n';
    else
        cout << pos[u] - pos[v] + add << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> n >> q;
    for (int i = 1; i <= n; ++i) {
        cin >> to[i];
        lift[i][0] = to[i];
    }

    for (int i = 1; i < L; ++i)
        for (int j = 1; j <= n; ++j)
            lift[j][i] = lift[lift[j][i - 1]][i - 1];

    memset(pos, -1, sizeof(pos));
    for (int i = 1; i <= n; ++i) {
        if (vis[i])
            continue;

        int v = i;
        vis[v] = 1;

        vector<int> here = {v};
        while (!vis[to[v]]) {
            v = to[v];
            here.push_back(v);
            vis[v] = 1;
        }

        if (pos[to[v]] == -1) {
            int en = to[v], c = 1;
            pos[en] = 0, cyc[en] = ++cc, ++sz[cc];
            while (here.back() != en) {
                pos[here.back()] = c++;
                cyc[here.back()] = cc;
                ++sz[cc];
                here.pop_back();
            }
            here.pop_back();
        }

        while (here.size()) {
            v = here.back();
            dist[v] = dist[to[v]] + 1;
            pos[v] = -2;
            here.pop_back();
        }
    }

    while (q--) {
        int u, v;
        cin >> u >> v;

        if (pos[u] >= 0 && pos[v] >= 0 && cyc[u] == cyc[v]) // same cycle
            same_cyc(u, v);
        else if (pos[u] == -2 && pos[v] >= 0) { // check if leads into cycle
            int p = jump(u, dist[u]);
            if (cyc[p] == cyc[v])
                same_cyc(p, v, dist[u]);
            else
                cout << "-1\n";
        }
        else if (pos[u] == -2 && pos[v] == -2) { // check if same arm
            if (dist[v] <= dist[u]) {
                if (jump(u, dist[u] - dist[v]) == v)
                    cout << dist[u] - dist[v] << '\n';
                else
                    cout << "-1\n";
            }
            else
                cout << "-1\n";
        }
        else
            cout << "-1\n";
    }
}
