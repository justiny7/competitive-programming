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

void solve() {
    int n;
    read(n);

    vector<int> a(n);
    read(a);

    map<int, vector<int>> mp;
    for (int i = 0; i < n; ++i)
        mp[a[i]].push_back(i);

    int ansmx = 1, ansl = 0, ansr = 0, ansx = a[0];
    for (auto [x, v] : mp) {
        vector<array<int, 3>> here = {{1, v[0], v[0]}};
        for (int i = 1; i < v.size(); ++i) {
            if (v[i] - v[i - 1] == 1) {
                ++here.back()[0];
                ++here.back()[2];
            } else {
                here.push_back({-(v[i] - v[i - 1] - 1), v[i - 1] + 1, v[i] - 1});
                here.push_back({1, v[i], v[i]});
            }
        }

        /*
        print(x);
        for (auto a : here)
            print(a);
        print("---");
        */

        int mx = -1, bst = 0, ben = 0;
        int cur = 0, st = 0;
        for (int i = 0; i < here.size(); ++i) {
            if (cur <= 0) {
                st = here[i][1];
                cur = here[i][0];
            } else {
                cur += here[i][0];
            }

            if (cur > mx) {
                mx = cur;
                bst = st;
                ben = here[i][2];
            }
        }

        // print(">", x, mx, bst, ben);

        if (ckmax(ansmx, mx)) {
            ansx = x;
            ansl = bst;
            ansr = ben;
        }
    }

    print(ansx, ansl + 1, ansr + 1);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t; read(t);
    while (t--)
        solve();
}

