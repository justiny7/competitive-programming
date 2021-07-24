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
    int n, k;
    read(n, k);

    vector<int> a(n), ans(n);
    read(a);


    vector<vector<int>> occ(n + 1);
    for (int i = 0; i < n; ++i)
        occ[a[i]].push_back(i);

    vector<vector<int>> add(k + 1);
    int ind = 1;
    for (int i = 1; i <= n; ++i) {
        if (occ[i].size() >= k) {
            for (int j = 0; j < k; ++j)
                ans[occ[i][j]] = j + 1;
        }
        else {
            for (int j = 0; j < occ[i].size(); ++j) {
                add[ind].push_back(occ[i][j]);
                ind = ind % k + 1;
                // print("new ind: ", ind);
            }
        }
    }

    // print(add);

    int mn = INT_MAX;
    for (int i = 1; i <= k; ++i)
        ckmin(mn, (int)add[i].size());

    for (int i = 1; i <= k; ++i) {
        for (int j = 0; j < mn; ++j)
            ans[add[i][j]] = i;
    }

    print(ans);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t; read(t);
    while (t--)
        solve();
}
