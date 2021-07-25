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

const int N = 169;
int n, k, a[N * N];

void solve() {
    read(n, k);

    for (int i = 1; i <= n * k; ++i)
        read(a[i]);

    set<int> need;
    for (int i = 1; i <= n; ++i)
        need.insert(i);

    vector<array<int, 2>> ans(n + 1);

    while (need.size()) {
        vector<int> lst(n + 1, -1);
        int l = 1, r = 1;

        while (l <= n * k) {
            while (r <= n * k && (!need.count(a[r]) || lst[a[r]] < 0)) {
                lst[a[r]] = r;
                ++r;
            }

            if (r > n * k)
                break;

            need.erase(a[r]);
            ans[a[r]] = {lst[a[r]], r};
            l = r = r + 1;
            lst.assign(n + 1, -1);
        }

        /*
        print("NEED:");
        for (int i : need)
            write(i, " ");
        print();
        */
    }

    for (int i = 1; i <= n; ++i)
        print(ans[i]);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    // int t; read(t);
    // while (t--)
    solve();
}
