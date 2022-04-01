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
    string s;
    cin >> n >> s;

    BIT<ll> ft[3];
    for (int i = 0; i < 3; ++i)
        ft[i].init(n * 2 + 69);

    int cur = n + 4;
    ll res = 0;
    for (char c : s) {
        ft[cur % 3].upd(cur, 1);
        cur += (c == '+' ? 1 : -1);
        res += ft[cur % 3].query(cur, n * 2 + 60);
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

