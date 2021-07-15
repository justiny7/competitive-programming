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

// hare and tortoise cycle thing
// after 2t moves, tortoise is position 0 in cycle, hare is position t
// after 2k moves, tortoise and hare meet
//  - tortoise is pos k, hare is pos (2k + t) % c
//  - k % c = (2k + t) % c
//  - (t + k) = 0 % c
//  Move another t times, then you reach pos 0 again

vector<vector<int>> move(vector<int> mv) {
    cout << "next";

    for (int i : mv)
        cout << " " << i;
    cout << endl;

    int k; cin >> k;
    if (k == 1) {
        string s; cin >> s;
        assert(s == "0123456789");

        cout << "done" << endl;
        exit(0);
    }

    vector<vector<int>> ret(k);
    for (int i = 0; i < k; ++i) {
        string s; cin >> s;
        for (char c : s)
            ret[i].push_back(c - '0');
    }

    return ret;
}

void solve() {
    while (1) {
        move({0});
        auto cur = move({0, 1});

        if (cur.size() == 2)
            break;
    }
    while (1)
        move({0, 1, 2, 3, 4, 5, 6, 7, 8, 9});
}

int main() {
    //cin.tie(0)->sync_with_stdio(0);

    //int t; read(t);
    //while (t--)
    solve();
}
