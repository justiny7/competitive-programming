#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 69, V = 101;
int n, q, a[N], ans[N], t[N * 4][V];

void push(int l, int r, int v) {
    if (l != r) {
        for (int i = 0; i < 2; ++i)
            for (int j = 1; j < V; ++j)
                t[v * 2 + i][j] = t[v][t[v * 2 + i][j]];
    }
    for (int i = 1; i < V; ++i)
        t[v][i] = i;
}
void build(int l = 0, int r = n - 1, int v = 1) {
    for (int i = 1; i < V; ++i)
        t[v][i] = i;
    if (l != r) {
        int m = l + r >> 1;
        build(l, m, v << 1);
        build(m + 1, r, v << 1 | 1);
    }
}
void upd(int ql, int qr, int x, int y, int l = 0, int r = n - 1, int v = 1) {
    if (ql > r || qr < l)
        return;
    if (l >= ql && r <= qr) {
        for (int i = 1; i < V; ++i)
            if (t[v][i] == x)
                t[v][i] = y;
        return;
    }
    push(l, r, v);
    int m = l + r >> 1;
    upd(ql, qr, x, y, l, m, v << 1);
    upd(ql, qr, x, y, m + 1, r, v << 1 | 1);
}
void get(int l = 0, int r = n - 1, int v = 1) {
    if (l == r) {
        ans[l] = t[v][a[l]];
        return;
    }
    push(l, r, v);
    int m = l + r >> 1;
    get(l, m, v << 1);
    get(m + 1, r, v << 1 | 1);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    build();
    cin >> q;
    while (q--) {
        int l, r, x, y;
        cin >> l >> r >> x >> y;
        upd(l - 1, r - 1, x, y);
    }
    get();
    for (int i = 0; i < n; ++i)
        cout << ans[i] << " \n"[i == n - 1];
}
