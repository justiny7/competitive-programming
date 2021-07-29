#include <bits/stdc++.h>
using namespace std;

const int N = 569, V = 1e5 + 69, K = 11;
int n, k, h[N], fav[V], cnt[V], dp[N][N * K];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> n >> k;

    for (int i = 0; i < n * k; ++i) {
        int x; cin >> x;
        ++cnt[x];
    }
    
    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        ++fav[x];
    }

    for (int i = 1; i <= k; ++i)
        cin >> h[i];

    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n * k; ++j)
            for (int take = 0; take <= k; ++take)
                if (j - take >= 0)
                    dp[i][j] = max(dp[i][j], dp[i - 1][j - take] + h[take]);

    int ans = 0;
    for (int i = 0; i < V; ++i)
        ans += dp[fav[i]][cnt[i]];

    cout << ans << '\n';
}

