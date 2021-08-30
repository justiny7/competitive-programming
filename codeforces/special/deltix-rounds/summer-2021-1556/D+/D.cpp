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

const int L = 31;

bool set_bit(int x, int bit) {
    return (x & (1 << bit));
}
int query(int i, int j, string op) {
    cout << op << " " << i << " " << j << endl;

    int ret;
    cin >> ret;
    return ret;
}
void guess(int k) {
    cout << "finish " << k << endl;
}

void solve() {
    int n, k;
    cin >> n >> k;

    vector<int> ands(n + 1), ors(n + 1);
    for (int i = 2; i <= n; ++i) {
        ands[i] = query(1, i, "and");
        ors[i] = query(1, i, "or");
    }

    int must = 0;
    int either = INT_MAX;
    for (int i = 2; i <= n; ++i) {
        for (int j = 0; j < L; ++j) {
            if (set_bit(ands[i], j))
                must |= (1 << j);
            else if (!set_bit(ors[i], j)) {
                // print("now either:", either, j);
                either &= (~(1 << j));
            }
        }

        // print("must:", must);
        // print("either:", either);
    }

    int confirm = query(2, 3, "or");
    for (int i = 0; i < L; ++i)
        if (set_bit(either, i) && set_bit(confirm, i))
            either ^= (1 << i);

    must |= either;

    vector<int> vals = {must};
    for (int i = 2; i <= n; ++i) {
        int cur = ands[i];
        for (int j = 0; j < L; ++j)
            if (set_bit(ors[i], j) && !set_bit(ands[i], j) && !set_bit(must, j))
                cur |= (1 << j);
        vals.push_back(cur);
    }

    sort(all(vals));
    // print(vals);
    guess(vals[k - 1]);
}

int main() {
    // cin.tie(0)->sync_with_stdio(0);

    // int t; read(t);
    // while (t--)
        solve();
}

