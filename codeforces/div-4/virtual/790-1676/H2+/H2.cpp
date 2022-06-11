#include <bits/stdc++.h>
using namespace std;

using ll = long long;

// BIT {{{
template<class T> struct BIT {
    int sz;
    vector<T> bit;

    void init(int _sz) {
        sz = _sz;
        bit.resize(sz, 0);
    }
    void upd(int i, T x) {
        for (++i; i < sz; i += i & -i)
            bit[i] += x;
    }
    T query(int i) {
        T ret = 0;
        for (++i; i; i -= i & -i)
            ret += bit[i];
        return ret;
    }
    T query(int l, int r) {
        return query(r) - query(l - 1);
    }
};
// }}}

void solve() {
    int n;
    cin >> n;

    vector<int> a(n + 1), cnt(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        ++cnt[a[i]];
    }

    ll res = 0;
    for (int i = 1; i <= n; ++i)
        res += 1LL * cnt[i] * (cnt[i] - 1) / 2;

    BIT<ll> ft;
    ft.init(n + 69);

    for (int i = n; i > 0; --i) {
        res += ft.query(0, a[i] - 1);
        ft.upd(a[i], 1);
    }

    cout << res << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--)
        solve();
}


