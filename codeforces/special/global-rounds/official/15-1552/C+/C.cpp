#include <bits/stdc++.h>
using namespace std;

// TEMPLATE {{{

/* Macros */
#define all(x) (x).begin(), (x).end()
#define finish(...) return void(print(__VA_ARGS__))

/* Input */
template<class T> void read(T &x) { cin >> x; }
template<class H, class T> void read(pair<H, T> &p) { cin >> p.first >> p.second; }
template<class T, size_t S> void read(array<T, S> &a) { for (T &i : a) read(i); }
template<class T> void read(vector<T> &v) { for (T &i : v) read(i); }

template<class H, class... T> void read(H &h, T &...t) { read(h); read(t...); }

/* Output */
template<class H, class T> ostream &operator<<(ostream &o, pair<H, T> &p) { o << p.first << " " << p.second; return o; }
template<class T, size_t S> ostream &operator<<(ostream &o, array<T, S> &a) { string s; for (T i : a) o << s << i, s = " "; return o; }
template<class T> ostream &operator<<(ostream &o, vector<T> &v) { string s; for (T i : v) o << s << i, s = " "; return o; }

template<class T> void write(T x) { cout << x; }
template<class H, class... T> void write(const H &h, const T &...t) { write(h); write(t...); }

void print() { write('\n'); }
template<class H, class... T> void print(const H &h, const T &...t) { write(h); if (sizeof...(t)) write(' '); print(t...); }

/* Misc */
bool ckmin(auto &a, const auto &b) { return (a > b) ? a = b, 1 : 0; }
bool ckmax(auto &a, const auto &b) { return (a < b) ? a = b, 1 : 0; }

using ll = long long;

// }}}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

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
    int n, k;
    read(n, k);

    vector<int> a(n * 2 + 1, -1);
    for (int i = 0; i < k; ++i) {
        int st, en;
        read(st, en);

        if (st > en)
            swap(st, en);

        a[st] = i;
        a[en] = i;
    }

    int cur = k, ncur = k;
    for (int i = 1; i <= n * 2; ++i) {
        if (a[i] < 0) {
            if (cur < n)
                a[i] = cur++;
            else
                a[i] = ncur++;
        }
    }

    // print(a);

    BIT<int> ft;
    int ans = 0;

    ft.init(n * 2 + 10);
    vector<int> lst(n, -1);
    for (int i = 1; i <= n * 2; ++i) {
        if (~lst[a[i]]) {
            // print(">", i, lst[a[i]]);
            ans += ft.query(lst[a[i]], i) - 1;
            ft.upd(lst[a[i]], -1);
        }
        else {
            lst[a[i]] = i;
            ft.upd(i, 1);
        }
    }

    print(ans);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t; read(t);
    while (t--)
        solve();
}
