#include <bits/stdc++.h>
using namespace std;

const int N = 35069, K = 101;
int n, k, a[N], lst[N], dp[K][N];

// Segtree {{{
int t[N * 4], lz[N * 4];

inline void push(int l, int r, int v) {
    if (l != r) {
        t[v * 2] += lz[v];
        t[v * 2 + 1] += lz[v];
        lz[v * 2] += lz[v];
        lz[v * 2 + 1] += lz[v];
    }
    lz[v] = 0;
}
void build(int b[], int l = 0, int r = n - 1, int v = 1) {
    lz[v] = 0;
    if (l == r)
        t[v] = b[l];
    else {
        int m = l + r >> 1;
        build(b, l, m, v * 2);
        build(b, m + 1, r, v * 2 + 1);
        t[v] = min(t[v * 2], t[v * 2 + 1]);
    }
}
void upd(int ql, int qr, int x, int l = 0, int r = n - 1, int v = 1) {
    if (ql > r || qr < l)
        return;
    if (l >= ql && r <= qr)
        t[v] += x, lz[v] += x;
    else {
        push(l, r, v);

        int m = l + r >> 1;
        upd(ql, qr, x, l, m, v * 2);
        upd(ql, qr, x, m + 1, r, v * 2 + 1);

        t[v] = min(t[v * 2], t[v * 2 + 1]);
    }
}
int query(int ql, int qr, int l = 0, int r = n - 1, int v = 1) {
    if (ql > r || qr < l)
        return INT_MAX;
    if (l >= ql && r <= qr)
        return t[v];

    push(l, r, v);
    int m = l + r >> 1;
    return min(query(ql, qr, l, m, v * 2), query(ql, qr, m + 1, r, v * 2 + 1));
}
// }}}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> n >> k;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    memset(dp, 0x3f, sizeof(dp));
    dp[0][0] = 0;

    for (int i = 1; i <= k; ++i) {
        build(dp[i - 1]);

        memset(lst, -1, sizeof(lst));
        dp[i][0] = 0;

        for (int j = 1; j <= n; ++j) {
            if (~lst[a[j]])
                upd(0, lst[a[j]] - 1, j - lst[a[j]]);

            lst[a[j]] = j;
            dp[i][j] = query(0, j - 1);
        }
    }

    cout << dp[k][n] << '\n';
}
