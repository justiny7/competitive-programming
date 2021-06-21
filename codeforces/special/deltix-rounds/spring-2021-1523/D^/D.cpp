#include <bits/stdc++.h>
using namespace std;
using ll = long long;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = 2e5 + 69, M = 61, K = 15;
int n, m, k, a[N][M], ord[N], dp[1 << K];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> n >> m >> k;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            char c; cin >> c;
            a[i][j] = c - '0';
        }
    }

    iota(ord, ord + n, 0);
    shuffle(ord, ord + n, rng);

    ll ans = 0;
    for (int t = 0; t < min(30, n); ++t) {
        int x = ord[t];

        vector<int> v;
        for (int i = 0; i < m; ++i)
            if (a[x][i])
                v.push_back(i);

        int sz = v.size();
        memset(dp, 0, sizeof(dp));
        for (int i = 0; i < n; ++i) {
            int here = 0;
            for (int j = 0; j < sz; ++j)
                if (a[i][v[j]])
                    here |= (1 << j);

            ++dp[here];
        }

        for (int i = 0; i < sz; ++i) // SOS dp
            for (int j = 0; j < (1 << sz); ++j)
                if (!(j & (1 << i)))
                    dp[j] += dp[j ^ (1 << i)];

        for (int i = 0; i < (1 << sz); ++i) {
            if (dp[i] >= (n + 1) / 2 && __builtin_popcountll(ans) < __builtin_popcountll(i)) {
                ans = 0;
                for (int j = 0; j < sz; ++j)
                    if (i & (1 << j))
                        ans |= (1LL << v[j]);
            }
        }
    }

    for (int i = 0; i < m; ++i)
        cout << ((ans & (1LL << i)) ? 1 : 0);
    cout << '\n';
}
