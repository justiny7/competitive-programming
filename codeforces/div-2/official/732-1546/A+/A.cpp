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
    int n; read(n);
    vector<int> a(n), b(n);
    read(a, b);

    if (accumulate(all(a), 0) != accumulate(all(b), 0))
        finish(-1);

    vector<array<int, 2>> ans;
    for (int i = 0; i < n - 1; ++i) {
        while (a[i] != b[i]) {
            if (a[i] < b[i]) {
                int j = i + 1;
                for (; j < n; ++j)
                    if (a[j] > b[j])
                        break;

                //print("?", i, j);
                ++a[i], --a[j];
                ans.push_back({j + 1, i + 1});
            }
            else {
                int j = i + 1;
                for (; j < n; ++j)
                    if (a[j] < b[j])
                        break;

                --a[i], ++a[j];
                ans.push_back({i + 1, j + 1});
            }
        }
    }

    print(ans.size());
    for (auto v : ans)
        print(v);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t; read(t);
    while (t--)
        solve();
}
