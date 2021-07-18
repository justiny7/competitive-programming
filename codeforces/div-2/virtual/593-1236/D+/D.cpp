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

void solve() {
    ll n, m, k;
    read(n, m, k);

    vector<set<ll>> row(n + 1), col(m + 1);
    for (int i = 0; i < k; ++i) {
        int r, c;
        read(r, c);

        row[r].insert(c);
        col[c].insert(r);
    }

    for (int i = 1; i <= n; ++i) {
        row[i].insert(0);
        row[i].insert(m + 1);
    }
    for (int i = 1; i <= m; ++i) {
        col[i].insert(0);
        col[i].insert(n + 1);
    }

    ll need = n * m - k - 1;
    ll dir = 0, cr = 1, cc = 1;
    ll ub = 1, bb = n + 1, lb = 0, rb = m + 1;

    if (*row[1].upper_bound(1) == 2)
        dir = 1;

    while (1) {
        //print(cr, cc, ub, bb, lb, rb);
        ll cur, nxt;
        if (dir == 0) {
            cur = cc;
            nxt = min(rb, *row[cr].upper_bound(cc));
            rb = cc = nxt - 1;
        }
        else if (dir == 1) {
            cur = cr;
            nxt = min(bb, *col[cc].upper_bound(cr));
            bb = cr = nxt - 1;
        }
        else if (dir == 2) {
            cur = cc;
            nxt = max(lb, *prev(row[cr].lower_bound(cc)));
            lb = cc = nxt + 1;
        }
        else {
            cur = cr;
            nxt = max(ub, *prev(col[cc].lower_bound(cr)));
            ub = cr = nxt + 1;
        }

        //print(dir, cur, nxt);

        if (abs(cur - nxt) == 1)
            break;

        need -= abs(cur - nxt) - 1;
        dir = (dir + 1) % 4;
    }

    print(need ? "No" : "Yes");
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    //int t; read(t);
    //while (t--)
    solve();
}
