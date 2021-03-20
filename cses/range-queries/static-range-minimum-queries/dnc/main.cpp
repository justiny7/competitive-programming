#include <bits/stdc++.h>
using namespace std;

const int mxN = 2e5 + 1;
int n, q, a[mxN], ans[mxN], lmn[mxN], rmn[mxN];
pair<int, int> qu[mxN];

void dnc(vector<int> cur, int l = 0, int r = n - 1) {
    if (cur.empty())
        return;
    if (l == r) {
        for (int i : cur)
            ans[i] = a[l];
        return;
    }
    int m = l + r >> 1;
    lmn[m] = a[m];
    rmn[m + 1] = a[m + 1];
    for (int i = m - 1; i >= l; --i)
        lmn[i] = min(a[i], lmn[i + 1]);
    for (int i = m + 2; i <= r; ++i)
        rmn[i] = min(rmn[i - 1], a[i]);
    vector<int> nxt[2];
    for (int i : cur) {
        int fi = qu[i].first, se = qu[i].second;
        if (fi <= m && m < se)
            ans[i] = min(lmn[fi], rmn[se]);
        else
            nxt[fi > m].push_back(i);
    }
    dnc(nxt[0], l, m);
    dnc(nxt[1], m + 1, r);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> q;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    for (int i = 0; i < q; ++i) {
        cin >> qu[i].first >> qu[i].second;
        --qu[i].first, --qu[i].second;
    }
    vector<int> nxt(q);
    for (int i = 0; i < q; ++i)
        nxt[i] = i;
    dnc(nxt);
    for (int i = 0; i < q; ++i)
        cout << ans[i] << '\n';
}
