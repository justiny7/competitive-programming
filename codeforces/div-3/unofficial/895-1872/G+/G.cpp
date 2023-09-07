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

    vector<ll> a(n);
    read(a);

    if (n == 1)
        finish(1, 1);

    ll tot = 1;
    for (ll i : a) {
        tot *= i;
        if (tot >= 1e9)
            break;
    }

    if (tot >= 1e9) {
        int l = 0, r = n - 1;
        while (a[l] == 1)
            l++;
        while (a[r] == 1)
            r--;

        finish(l + 1, r + 1);
    }

    vector<int> pos;
    for (int i = 0; i < n; i++)
        if (a[i] != 1)
            pos.push_back(i);

    if (pos.size() < 2)
        finish(1, 1);

    vector<ll> sum(n), prod(n);
    for (int i = 0; i < n; ++i) {
        sum[i] = prod[i] = a[i];
        if (i) {
            sum[i] += sum[i - 1];
            prod[i] *= prod[i - 1];
        }
    }

    // print("HI");
    int sz = pos.size();
    int l = 0, r = 0;
    ll best = 0;
    for (int i = 0; i < sz; i++) {
        for (int j = i; j < sz; j++) {
            ll here = (pos[i] ? sum[pos[i] - 1] : 0);
            here += prod[pos[j]] / (pos[i] ? prod[pos[i] - 1] : 1);
            here += sum[n - 1] - sum[pos[j]];

            // print(">", pos[i], pos[j], here);

            if (here > best) {
                best = here;
                l = pos[i], r = pos[j];
            }
        }
    }

    print(l + 1, r + 1);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t; read(t);
    while (t--)
        solve();
}

