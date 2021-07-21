#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 69;
int n, m, x;

struct node {
    long long ans = 0;
    vector<array<int, 2>> pref, suff; // {value, step} (at most log(N) different values)

    node() {}
    node(int v) {
        pref = suff = {{v, 1}};
        ans = (v >= x);
    }
} t[N * 4];

vector<array<int, 2>> comb(const vector<array<int, 2>> &a, const vector<array<int, 2>> &b) {
    vector<array<int, 2>> ret = a;
    if (ret.empty())
        ret.push_back({b[0][0], 0});

    for (auto ar : b) {
        if ((ret.back()[0] | ar[0]) == ret.back()[0])
            ret.back()[1] += ar[1];
        else
            ret.push_back({ret.back()[0] | ar[0], ar[1]});
    }

    return ret;
}
node comb(const node &a, const node &b) {
    node ret;

    ret.ans = a.ans + b.ans;
    ret.pref = comb(a.pref, b.pref);
    ret.suff = comb(b.suff, a.suff);

    for (int i = 0, j = b.pref.size(), s = 0; i < a.suff.size(); ++i) {
        while (j > 0 && (a.suff[i][0] | b.pref[j - 1][0]) >= x)
            s += b.pref[--j][1];
        ret.ans += 1LL * a.suff[i][1] * s;
    }

    return ret;
}

void upd(int i, int q, int l = 0, int r = n - 1, int v = 1) {
    if (l == r)
        t[v] = node(q);
    else {
        int m = l + r >> 1;
        if (i <= m)
            upd(i, q, l, m, v * 2);
        else
            upd(i, q, m + 1, r, v * 2 + 1);
        t[v] = comb(t[v * 2], t[v * 2 + 1]);
    }
}
node query(int ql, int qr, int l = 0, int r = n - 1, int v = 1) {
    if (ql > r || qr < l)
        return node();
    if (l >= ql && r <= qr)
        return t[v];
    int m = l + r >> 1;
    return comb(query(ql, qr, l, m, v * 2), query(ql, qr, m + 1, r, v * 2 + 1));
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> n >> m >> x;
    for (int i = 0; i < n; ++i) {
        int v; cin >> v;
        upd(i, v);
    }

    while (m--) {
        int t; cin >> t;

        if (t & 1) {
            int i, q;
            cin >> i >> q;
            upd(i - 1, q);
        }
        else {
            int l, r;
            cin >> l >> r;
            cout << query(l - 1, r - 1).ans << '\n';
        }
    }
}
