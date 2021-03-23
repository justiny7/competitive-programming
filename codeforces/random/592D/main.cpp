#include <bits/stdc++.h>
using namespace std;

const int mxN = 150'000;
int n, m, st, mxl = -1, tot, cnt[mxN], dist[mxN], far[mxN];
vector<int> adj[mxN];
bool mk[mxN];

bool cmp(int a, int b) {
    if (a < 0)
        return 0;
    if (b < 0)
        return 1;
    if (dist[a] != dist[b])
        return dist[a] > dist[b];
    return a < b;
}

void dfs(int v = 1, int p = 0, int d = 0) {
    int a = -1, b = -1;
    dist[v] = d;
    if (mk[v])
        a = v;
    for (int u : adj[v]) {
        if (u == p)
            continue;
        dfs(u, v, d + 1);
        if (far[u] < 0)
            continue;
        vector<int> here = {a, b, far[u]};
        sort(here.begin(), here.end(), cmp);
        a = here[0], b = here[1];
    }
    if (~a && ~b) {
        int diam = dist[a] + dist[b] - 2 * dist[v];
        if (mxl < diam) {
            mxl = diam;
            st = min(a, b);
        }
        else if (mxl == diam)
            st = min({st, a, b});
    }
    far[v] = a;
}
void dfs2(int v = st, int p = 0) {
    for (int u : adj[v])
        if (u != p)
            dfs2(u, v), cnt[v] += cnt[u];
}
void dfs3(int v = st, int p = 0) {
    for (int u : adj[v])
        if (u != p && cnt[u])
            ++tot, dfs3(u, v);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    for (int i = 1; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for (int i = 0; i < m; ++i) {
        int x; cin >> x;
        cnt[x] = mk[x] = 1;
    }
    if (m == 1) {
        for (int i = 1; i <= n; ++i)
            if (mk[i])
                cout << i << '\n';
        cout << "0\n";
        return 0;
    }
    dfs(); dfs2(); dfs3();
    cout << st << '\n' << tot * 2 - mxl << '\n';
}
