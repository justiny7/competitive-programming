#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 69;
int n, m, ans, a[N];
vector<pair<int, int>> rb[N], lb[N];
set<int> cur, ret;

//Segtree {{{
int tmn[N * 4], tmx[N * 4], lz[N * 4];

inline void push(int l, int r, int v) {
    if (l != r) {
        tmn[v << 1] += lz[v];
        tmn[v << 1 | 1] += lz[v];
        tmx[v << 1] += lz[v];
        tmx[v << 1 | 1] += lz[v];
        lz[v << 1] += lz[v];
        lz[v << 1 | 1] += lz[v];
    }
    lz[v] = 0;
}
void upd(int ql, int qr, int x, int l = 1, int r = n, int v = 1) {
    if (ql > r || qr < l)
        return;
    if (l >= ql && r <= qr) {
        tmn[v] += x, tmx[v] += x, lz[v] += x;
        return;
    }
    push(l, r, v);
    int m = l + r >> 1;
    upd(ql, qr, x, l, m, v << 1);
    upd(ql, qr, x, m + 1, r, v << 1 | 1);
    tmn[v] = min(tmn[v << 1], tmn[v << 1 | 1]);
    tmx[v] = max(tmx[v << 1], tmx[v << 1 | 1]);
}
//}}}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        cin >> a[i], upd(i, i, a[i]);
    for (int i = 1; i <= m; ++i) {
        int l, r;
        cin >> l >> r;
        rb[r].emplace_back(l, i);
        lb[l].emplace_back(r, i);
        upd(l, r, -1);
        cur.insert(i);
    }
    ans = tmx[1] - tmn[1];
    ret = cur;
    for (int i = 1; i <= n; ++i) {
        for (auto [x, ind] : lb[i]) {
            upd(i, x, 1);
            cur.erase(ind);
        }
        for (auto [x, ind] : rb[i - 1]) {
            upd(x, i - 1, -1);
            cur.insert(ind);
        }
        if (ans < tmx[1] - tmn[1]) {
            ans = tmx[1] - tmn[1];
            ret = cur;
        }
    }
    cout << ans << '\n' << ret.size() << '\n';
    for (int i : ret)
        cout << i << " ";
    cout << '\n';
}
