#include <bits/stdc++.h>
using namespace std;

const int N = 69, M = 2e4 + 69;
int n, m, k, a[N][M], pref[N][M], dp[N][M];

// Lazy Segtree {{{
int t[M * 4], lz[M * 4];

inline void push(int l, int r, int v) {
    if (l != r) {
        t[v * 2] += lz[v];
        t[v * 2 + 1] += lz[v];
        lz[v * 2] += lz[v];
        lz[v * 2 + 1] += lz[v];
    }
    lz[v] = 0;
}
void upd(int ql, int qr, int x, int l = 1, int r = m + 1, int v = 1) {
    if (ql > r || qr < l)
        return;
    if (l >= ql && r <= qr)
        t[v] += x, lz[v] += x;
    else {
        push(l, r, v);
        int mid = l + r >> 1;
        upd(ql, qr, x, l, mid, v * 2);
        upd(ql, qr, x, mid + 1, r, v * 2 + 1);
        t[v] = max(t[v * 2], t[v * 2 + 1]);
    }
}
// }}}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> n >> m >> k;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> a[i][j];
            pref[i][j] = pref[i][j - 1] + a[i][j];
        }
    }

    for (int i = 1; i <= n; ++i) {
        memset(t, 0, sizeof(t));
        memset(lz, 0, sizeof(lz));

        for (int j = 1; j + k - 1 <= m; ++j)
            upd(j, j, dp[i - 1][j]);
        for (int j = 1; j <= k; ++j)
            upd(1, j, -a[i][j]);

        for (int j = 1; j + k - 1 <= m; ++j) {
            dp[i][j] = t[1] + pref[i][j + k - 1] - pref[i][j - 1] + pref[i + 1][j + k - 1] - pref[i + 1][j - 1];

            if (j + k <= m) {
                upd(max(1, j - k + 1), j, a[i][j]);
                upd(j + 1, j + k, -a[i][j + k]);
            }
        }
    }

    cout << *max_element(dp[n] + 1, dp[n] + m + 1) << '\n';
}
