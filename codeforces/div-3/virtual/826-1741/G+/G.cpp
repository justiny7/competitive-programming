#include <bits/stdc++.h>
using namespace std;

const int N = 1e4 + 69, K = 6;
int n, m, nh, k;
int d[N], has_car[N];
vector<int> adj[N], friends, no_car[N];
bool pos[N][1 << K];

void bfs() {
    memset(d, -1, sizeof(d));
    d[1] = 0;

    queue<int> q;
    q.push(1);
    while (q.size()) {
        int v = q.front();
        q.pop();

        for (int u : adj[v]) {
            if (d[u] < 0) {
                d[u] = d[v] + 1;
                q.push(u);
            }
        }
    }
}

void solve() {
    cin >> n >> m;

    for (int i = 1; i <= n; ++i) {
        has_car[i] = 0;
        no_car[i].clear();
        adj[i].clear();
    }

    while (m--) {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    cin >> nh;
    friends.clear();
    while (nh--) {
        int x;
        cin >> x;

        friends.push_back(x);
        ++has_car[x];
    }

    cin >> k;
    for (int i = 0; i < k; ++i) {
        int x;
        cin >> x, --x;

        // cout << "f: " << friends[x] << '\n';
        --has_car[friends[x]];
        no_car[friends[x]].push_back(i);
    }

    bfs();

    // for (int i = 1; i <= n; ++i)
        // cout << "> " << i << " " << d[i] << '\n';

    memset(pos, 0, sizeof(pos));
    pos[1][0] = 1;

    queue<array<int, 2>> q;
    q.push({1, 0});
    while (q.size()) {
        auto [v, msk] = q.front();
        q.pop();

        // cout << "at " << v << " with msk " << bitset<6>(msk) << '\n';

        for (int u : adj[v]) {
            int nmsk = msk;
            for (int j : no_car[u])
                nmsk |= (1 << j);

            if (!pos[u][nmsk] && d[u] == d[v] + 1) {
                pos[u][nmsk] = 1;
                q.push({u, nmsk});
            }
        }
    }

    vector<vector<int>> have(n + 1);
    for (int i = 1; i <= n; ++i)
        for (int j = 0; j < (1 << k); ++j)
            if (pos[i][j])
                have[i].push_back(j);

    bool res[1 << K];
    memset(res, 0, sizeof(res));
    res[0] = 1;
    for (int i = 1; i <= n; ++i) {
        while (has_car[i]--) {
            bool nres[1 << K];
            for (int j = 0; j < (1 << K); ++j)
                nres[j] = res[j];

            for (int j = 0; j < (1 << K); ++j)
                if (res[j])
                    for (int msk : have[i])
                        nres[j | msk] = 1;

            for (int j = 0; j < (1 << K); ++j)
                res[j] = nres[j];
        }

    }

    int ans = INT_MAX;
    for (int i = 0; i < (1 << K); ++i)
        if (res[i])
            ans = min(ans, k - __builtin_popcount(i));

    cout << ans << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--)
        solve();
}

