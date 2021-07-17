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
template<class T> bool ckmin(T &a, const T b) { return (b < a) ? a = b, 1 : 0; }
template<class T> bool ckmax(T &a, const T b) { return (a < b) ? a = b, 1 : 0; }

using ll = long long;

// }}}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

const int N = 1e4 + 69, D = 5e3 + 10;
int n;
vector<array<int, 3>> ver, hor;

// BIT {{{
ll bit[N];

void upd(int i, ll x) {
    for (++i; i < N; i += i & -i)
        bit[i] += x;
}
ll query(int i) {
    ll ret = 0;
    for (++i; i; i -= i & -i)
        ret += bit[i];
    return ret;
}
ll query(int l, int r) {
    return query(r) - query(l - 1);
}
// }}}

void solve() {
    read(n);

    for (int i = 0; i < n; ++i) {
        int x1, y1, x2, y2;
        read(x1, y1, x2, y2);

        if (x1 > x2)
            swap(x1, x2);
        if (y1 > y2)
            swap(y1, y2);

        x1 += D, y1 += D, x2 += D, y2 += D;

        if (x1 == x2)
            ver.push_back({x1, y1, y2});
        else
            hor.push_back({y1, x1, x2});
    }

    sort(all(ver));

    int vsz = ver.size();
    ll ans = 0;
    for (int i = 0; i < vsz; ++i) {
        auto [cx, bt, tp] = ver[i];

        vector<array<int, 2>> endings;
        for (auto [y, st, en] : hor) {
            if (st <= cx && en > cx && y >= bt && y <= tp) {
                upd(y, 1);
                endings.push_back({en, y});
            }
        }

        sort(all(endings));

        //print("for i = ", i);
        //for (auto v : endings)
        //print(v);

        int ei = 0, esz = endings.size();
        for (int j = i + 1; j < vsz; ++j) {
            auto [nx, nbt, ntp] = ver[j];

            while (ei < esz && endings[ei][0] < nx)
                upd(endings[ei++][1], -1);

            ll here = query(nbt, ntp);
            ans += here * (here - 1) / 2;

            //print(">", i, j, here);
        }

        while (ei < esz)
            upd(endings[ei++][1], -1);
    }

    print(ans);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    //int t; read(t);
    //while (t--)
    solve();
}
