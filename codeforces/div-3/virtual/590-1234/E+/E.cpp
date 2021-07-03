#include <bits/stdc++.h>
using namespace std;

//TEMPLATE {{{

//Macros
#define all(x) (x).begin(), (x).end()
#define finish(...) return void(print(__VA_ARGS__))

//Input
template<class T> void read(T &x) { cin >> x; }
template<class H, class T> void read(pair<H, T> &p) { cin >> p.first >> p.second; }
template<class T, size_t S> void read(array<T, S> &a) { for (T &i : a) read(i); }
template<class T> void read(vector<T> &v) { for (T &i : v) read(i); }

template<class H, class... T> void read(H &h, T &...t) { read(h); read(t...); }

//Output
template<class H, class T> ostream &operator<<(ostream &o, pair<H, T> &p) { o << p.first << " " << p.second; return o; }
template<class T, size_t S> ostream &operator<<(ostream &o, array<T, S> &a) { string s; for (T i : a) o << s << i, s = " "; return o; }
template<class T> ostream &operator<<(ostream &o, vector<T> &v) { string s; for (T i : v) o << s << i, s = " "; return o; }

template<class T> void write(T x) { cout << x; }
template<class H, class... T> void write(const H &h, const T &...t) { write(h); write(t...); }

void print() { write('\n'); }
template<class H, class... T> void print(const H &h, const T &...t) { write(h); if (sizeof...(t)) write(' '); print(t...); }

//Misc
template<class T> bool ckmin(T &a, const T b) { return (b < a) ? a = b, 1 : 0; }
template<class T> bool ckmax(T &a, const T b) { return (a < b) ? a = b, 1 : 0; }

using ll = long long;

//Constants
const ll M = 1e9 + 7; //998244353;
const int dr[] = {1, 0, -1, 0}, dc[] = {0, 1, 0, -1};

//}}}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void solve() {
    int n, m;
    read(n, m);

    vector<ll> a(m), ans(n), abvcnt(n + 1), belowsum(n + 1), belowcontrib(n + 1), abvcntpref(n + 1), active(n + 1);
    read(a);

    ll cur = 0;
    for (int i = 1; i < m; ++i) {
        cur += abs(a[i] - a[i - 1]);

        if (a[i - 1] < a[i]) {
            ++active[a[i - 1] + 1];
            --active[a[i]];

            abvcnt[a[i - 1]]++;
            belowsum[a[i]] += a[i - 1];
            belowcontrib[a[i]] += abs(a[i] - a[i - 1]);
        }
        else if (a[i - 1] > a[i]) {
            ++active[a[i] + 1];
            --active[a[i - 1]];

            abvcnt[a[i]]++;
            belowsum[a[i - 1]] += a[i];
            belowcontrib[a[i - 1]] += abs(a[i] - a[i - 1]);
        }
    }
    ans[0] = cur;

    ll pref = 0;
    for (int i = 1; i <= n; ++i) {
        pref += active[i];
        abvcntpref[i] = pref;
    }

    //for (int i = 1; i <= n; ++i)
    //print(i, abvcnt[i], belowsum[i], belowcontrib[i], abvcntpref[i]);

    for (int i = 1; i <= n; ++i)
        ans[i - 1] = ans[0] - belowcontrib[i] + belowsum[i] + abvcnt[i] * (i - 1) - abvcntpref[i];

    print(ans);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    //int t; read(t);
    //while (t--)
    solve();
}
