#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 69;
int n, o, dp[N * 2], a[N * 2];

//Segtree {{{
int tmx[N * 8], tmn[N * 8];
void build(int l = 0, int r = n * 2 - 1, int v = 1) {
    if (l == r) {
        tmx[v] = tmn[v] = a[l];
        return;
    }
    int m = l + r >> 1;
    build(l, m, v << 1);
    build(m + 1, r, v << 1 | 1);
    tmn[v] = min(tmn[v << 1], tmn[v << 1 | 1]);
    tmx[v] = max(tmx[v << 1], tmx[v << 1 | 1]);
}
int query(bool f, int ql, int qr, int l = 0, int r = n * 2 - 1, int v = 1) {
    if (ql > r || qr < l)
        return (f ? INT_MIN : INT_MAX);
    if (l >= ql && r <= qr)
        return (f ? tmx[v] : tmn[v]);
    int m = l + r >> 1,
        lc = query(f, ql, qr, l, m, v << 1),
        rc = query(f, ql, qr, m + 1, r, v << 1 | 1);
    return (f ? max(lc, rc) : min(lc, rc));
}
//}}}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    int mx = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i], a[i + n] = a[i];
        mx = max(mx, a[i]);
    }
    for (int i = n - 1; ~i; --i) {
        if (a[i] == mx) {
            o = n - i - 1;
            rotate(a, a + i + 1, a + n * 2);
            break;
        }
    }
    build();
    if (query(0, 0, n - 1) * 2 >= query(1, 0, n - 1)) {
        for (int i = 0; i < n; ++i)
            cout << -1 << " \n"[i == n - 1];
        return 0;
    }
    for (int i = n - 1; ~i; --i) {
        int tl = i + 1, tr = n * 2 - 1;
        while (tl < tr) {
            int m = tl + tr >> 1;
            if (query(1, i + 1, m) >= a[i])
                tr = m;
            else
                tl = m + 1;
        }
        int l = i, r = tl, best = -1;
        while (l <= r) {
            int m = l + r >> 1;
            if (query(0, i, m) * 2 < a[i])
                best = m, r = m - 1;
            else
                l = m + 1;
        }
        if (~best)
            dp[i] = best - i;
        else
            dp[i] = dp[r] + r - i;
    }
    for (int i = 0; i < n; ++i)
        cout << dp[(i + o) % n] << " \n"[i == n - 1];
}
