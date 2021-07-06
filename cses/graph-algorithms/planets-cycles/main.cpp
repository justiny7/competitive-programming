#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 69, L = 19;
int n, cc, to[N], cyc[N], dist[N], sz[N], lift[N][L];
bool vis[N];

int jump(int v, int k) {
    for (int i = 0; i < L; ++i)
        if (k & (1 << i))
            v = lift[v][i];
    return v;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> to[i];
        lift[i][0] = to[i];
    }

    for (int i = 1; i < L; ++i)
        for (int j = 1; j <= n; ++j)
            lift[j][i] = lift[lift[j][i - 1]][i - 1];

    memset(cyc, -1, sizeof(cyc));
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

        if (cyc[to[v]] == -1) {
            int en = to[v];
            cyc[en] = ++cc, ++sz[cc];
            while (here.back() != en) {
                cyc[here.back()] = cc;
                ++sz[cc];
                here.pop_back();
            }
            here.pop_back();
        }

        while (here.size()) {
            v = here.back();
            dist[v] = dist[to[v]] + 1;
            cyc[v] = 0;
            here.pop_back();
        }
    }

    for (int i = 1; i <= n; ++i)
        cout << sz[cyc[jump(i, dist[i])]] + dist[i] << " \n"[i == n];
}
