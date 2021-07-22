#include <bits/stdc++.h>
using namespace std;

using ll = long long;

// BIT {{{
template<class T> struct BIT {
    int sz;
    vector<T> bit;

    void init(int _sz) {
        sz = _sz;
        bit.resize(sz);
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

const int N = 2e5 + 69, V = 3e5 + 69;
int n; ll ans, pref;
BIT<ll> sum, cnt;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> n;

    sum.init(V), cnt.init(V);

    for (int i = 0; i < n; ++i) {
        int x; cin >> x;

        ans += 1LL * x * i + sum.query(x) + pref;
        pref += x;

        for (int j = x; j < V; j += x) {
            ans -= 1LL * j * cnt.query(j, min(V, j + x - 1));
            sum.upd(j, -x);
        }

        cnt.upd(x, 1);
        cout << ans << " \n"[i == n - 1];
    }
}
