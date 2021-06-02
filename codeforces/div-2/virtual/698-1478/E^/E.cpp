#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 69;
int n, q;
string s, g;
array<int, 2> ops[N];

//Lazy segtree {{{
int t[N * 4], lz[N * 4];

inline void push(int l, int r, int v) {
    if (~lz[v] && l != r) {
        int m = l + r >> 1;
        t[v * 2] = lz[v] * (m - l + 1);
        t[v * 2 + 1] = lz[v] * (r - m);
        lz[v * 2] = lz[v * 2 + 1] = lz[v];
    }
    lz[v] = -1;
}
void upd(int ql, int qr, int x, int l = 0, int r = n - 1, int v = 1) {
    if (ql > r || qr < l)
        return;
    if (l >= ql && r <= qr) {
        t[v] = (r - l + 1) * x;
        lz[v] = x;
        return;
    }
    push(l, r, v);
    int m = l + r >> 1;
    upd(ql, qr, x, l, m, v * 2);
    upd(ql, qr, x, m + 1, r, v * 2 + 1);
    t[v] = t[v * 2] + t[v * 2 + 1];
}
int query(int ql, int qr, int l = 0, int r = n - 1, int v = 1) {
    if (ql > r || qr < l)
        return 0;
    if (l >= ql && r <= qr)
        return t[v];
    push(l, r, v);
    int m = l + r >> 1;
    return query(ql, qr, l, m, v * 2) + query(ql, qr, m + 1, r, v * 2 + 1);
}
//}}}

void solve() {
    cin >> n >> q >> s >> g;
    for (int i = 0; i < n * 4; ++i)
        t[i] = 0, lz[i] = -1;
    for (int i = 0; i < q; ++i) {
        cin >> ops[i][0] >> ops[i][1];
        --ops[i][0], --ops[i][1];
    }
    for (int i = 0; i < n; ++i)
        upd(i, i, g[i] - '0');
    for (int i = q - 1; ~i; --i) {
        auto [l, r] = ops[i];
        int c = query(l, r), d = r - l + 1;
        if (d % 2 == 0 && c == d / 2) {
            cout << "NO\n";
            return;
        }
        if (c <= d / 2)
            upd(l, r, 0);
        else
            upd(l, r, 1);
    }
    bool f = 1;
    for (int i = 0; i < n; ++i)
        f &= (query(i, i) == (s[i] - '0'));
    cout << (f ? "YES" : "NO") << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int tt; cin >> tt;
    while (tt--)
        solve();
}
