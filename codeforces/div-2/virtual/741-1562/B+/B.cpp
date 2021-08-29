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

set<int> prime = {2, 3, 5, 7};

bool is_prime(int x) {
    for (int i = 2; i * i <= x; ++i)
        if (x % i == 0)
            return 0;
    return 1;
}

void solve() {
    int n;
    string s;
    read(n, s);

    for (char c : s) {
        int dig = c - '0';
        if (!prime.count(dig)) {
            print(1);
            finish(dig);
        }
    }

    map<int, int> mp;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '2' && i) {
            print(2);
            write(s[i - 1], s[i]);
            finish();
        }

        ++mp[s[i] - '0'];
    }

    for (auto [x, c] : mp) {
        if (c > 1) {
            print(2);
            write(x, x);
            finish();
        }
    }

    vector<int> cur;
    for (int i = 0; i < n; ++i)
        if (prime.count(s[i] - '0'))
            cur.push_back(s[i] - '0');

    int sz = cur.size(), ans = INT_MAX;
    for (int i = 1; i < (1 << sz); ++i) {
        int here = 0;
        for (int j = 0; j < sz; ++j)
            if (i & (1 << j))
                here = here * 10 + cur[j];

        if (!is_prime(here))
            ckmin(ans, here);
    }
    
    assert(ans != INT_MAX);

    print(to_string(ans).size());
    print(ans);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t; read(t);
    while (t--)
        solve();
}

