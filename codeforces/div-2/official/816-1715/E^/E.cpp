#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int N = 1e5 + 69;
int n, m, k;
ll dp_before[N], dp_cur[N];
vector<array<ll, 2>> adj[N];

void compute(int l, int r, int optl, int optr) {
    if (l > r)
        return;

    int mid = l + r >> 1;
    array<ll, 2> best = {LLONG_MAX, -1};

    for (int i = optl; i <= optr; ++i)
        best = min(best, {dp_before[i] + 1LL * (mid - i) * (mid - i), i});

    dp_cur[mid] = best[0];

    int opt = best[1];
    compute(l, mid - 1, optl, opt);
    compute(mid + 1, r, opt, optr);
}
void dijk() {
    priority_queue<array<ll, 2>, vector<array<ll, 2>>, greater<>> pq;
    for (int i = 0; i < n; ++i)
        pq.push({dp_before[i], i});

    while (pq.size()) {
        auto [d, v] = pq.top();
        pq.pop();

        if (dp_before[v] < d)
            continue;

        for (auto [u, w] : adj[v]) {
            if (dp_before[u] > d + w) {
                dp_before[u] = d + w;
                pq.push({d + w, u});
            }
        }
    }
}
void solve() {
    memset(dp_before, 0x3f, sizeof(dp_before));
    dp_before[0] = 0;

    for (int i = 0; i < k; ++i) {
        dijk();
        compute(0, n - 1, 0, n - 1);

        for (int j = 0; j < n; ++j)
            dp_before[j] = dp_cur[j];
    }

    dijk();
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> n >> m >> k;

    while (m--) {
        ll u, v, w;
        cin >> u >> v >> w, --u, --v;

        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    solve();

    for (int i = 0; i < n; ++i)
        cout << dp_before[i] << " \n"[i == n - 1];
}

