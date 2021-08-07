#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define uid(a, b) uniform_int_distribution<int>((a), (b))(rng)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll MD[2] = {(ll)1e9 + 7, (ll)1e9 + 9}, B = uid(501, MD[0] - 2);

const int N = 3e5 + 69;
int n, val[N];
char col[N];
vector<int> adj[N];
array<ll, 2> hsh[N];

void dfs_hash(int v = 1, int p = 0, array<ll, 2> cur = {0, 0}, array<ll, 2> po = {1, 1}) {
    for (int c = 0; c < 2; ++c)
        (cur[c] += col[v] * po[c] % MD[c]) %= MD[c];
    for (int c = 0; c < 2; ++c)
        (po[c] *= B) %= MD[c];

    hsh[v] = cur;

    for (int u : adj[v])
        if (u != p)
            dfs_hash(u, v, cur, po);
}
set<array<ll, 2>> dfs_ans(int v = 1, int p = 0) {
    set<array<ll, 2>> ret = {hsh[v]};

    for (int u : adj[v]) {
        if (u == p)
            continue;

        set<array<ll, 2>> cur = dfs_ans(u, v);
        if (cur.size() > ret.size())
            swap(cur, ret);

        for (auto x : cur)
            ret.insert(x);
    }

    val[v] += ret.size();
    return ret;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> n;

    for (int i = 1; i <= n; ++i)
        cin >> val[i];

    for (int i = 1; i <= n; ++i)
        cin >> col[i];

    for (int i = 1, u, v; i < n; ++i) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs_hash(); dfs_ans();

    int mx = *max_element(val + 1, val + n + 1);
    cout << mx << '\n';
    cout << count(val + 1, val + n + 1, mx) << '\n';
}

