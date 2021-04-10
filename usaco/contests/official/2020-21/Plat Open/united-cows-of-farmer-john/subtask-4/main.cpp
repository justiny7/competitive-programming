#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 2e5 + 69;
int n, a[N]; ll ans;
vector<int> lst[N];

//Segtree {{{
ll t[N * 4], lz[N * 4], cnt[N * 4];
inline void push(int l, int r, int v) {
    if (l != r) {
        lz[v << 1] += lz[v];
        lz[v << 1 | 1] += lz[v];
        t[v << 1] += lz[v] * cnt[v << 1];
        t[v << 1 | 1] += lz[v] * cnt[v << 1 | 1];
    }
    lz[v] = 0;
}
void upd(int ql, int qr, ll x, int l = 1, int r = n, int v = 1) {
    if (ql > r || qr < l)
        return;
    if (l >= ql && r <= qr) {
        t[v] += cnt[v] * x, lz[v] += x;
        return;
    }
    push(l, r, v);
    int m = l + r >> 1;
    upd(ql, qr, x, l, m, v << 1);
    upd(ql, qr, x, m + 1, r, v << 1 | 1);
    t[v] = t[v << 1] + t[v << 1 | 1];
}
void upd2(int i, ll x, int l = 1, int r = n, int v = 1) {
    if (l == r) {
        cnt[v] += x;
        return;
    }
    push(l, r, v);
    int m = l + r >> 1;
    if (i <= m)
        upd2(i, x, l, m, v << 1);
    else
        upd2(i, x, m + 1, r, v << 1 | 1);
    cnt[v] = cnt[v << 1] + cnt[v << 1 | 1];
}
ll query(int ql, int qr, int l = 1, int r = n, int v = 1) {
    if (ql > r || qr < l)
        return 0;
    if (l >= ql && r <= qr)
        return t[v];
    push(l, r, v);
    int m = l + r >> 1;
    return query(ql, qr, l, m, v << 1) + query(ql, qr, m + 1, r, v << 1 | 1);
}
int get(int i, int l = 1, int r = n, int v = 1) {
    if (l == r)
        return t[v];
    push(l, r, v);
    int m = l + r >> 1;
    if (i <= m)
        return get(i, l, m, v << 1);
    else
        return get(i, m + 1, r, v << 1 | 1);
}
//}}}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for (int i = 1; i <= n; ++i)
        lst[i].push_back(0);
    for (int i = 1; i <= n; ++i) {
        int x; cin >> x;
        ans += query(lst[x].back() + 1, i - 1);
        if (lst[x].size() > 1) {
            upd(lst[x].back(), lst[x].back(), -get(lst[x].back()));
            upd2(lst[x].back(), -1);
            upd(lst[x][lst[x].size() - 2] + 1, lst[x].back() - 1, -1);
        }
        upd2(i, 1);
        upd(lst[x].back() + 1, i - 1, 1);
        lst[x].push_back(i);
    }
    cout << ans << '\n';
}
