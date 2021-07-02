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
//const ll M = 1e9 + 7; //998244353;
const int dr[] = {1, 0, -1, 0}, dc[] = {0, 1, 0, -1};

//}}}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

const int N = 1e5 + 69;
int n, A, R, M;
ll a[N], pref[N];

// Guessing that answer is ternary searchable?
// Let f(H) = cost of making all pillars H
// O = sum of all max(0, a[i] - H)
// U = sum of all max(0, H - a[i])
// if (O > U), f(H) = MU + R(O - U)
// else, f(H) = MO + A(U - O)
ll cost(ll H) {
    int ind = lower_bound(a, a + n + 1, H) - a - 1;
    //print(H, ind);
    ll U = H * ind - pref[ind];
    ll O = (pref[n] - pref[ind]) - H * (n - ind);

    if (O > U)
        return M * U + R * (O - U);
    else
        return M * O + A * (U - O);
}

void solve() {
    read(n, A, R, M);
    ckmin(M, A + R);

    for (int i = 1; i <= n; ++i)
        read(a[i]);

    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; ++i)
        pref[i] = pref[i - 1] + a[i];

    //print(cost(8));

    int lo = 0, hi = 1e9;
    while (hi - lo >= 1e6) {
        int l = lo + (hi - lo) / 3,
            r = hi - (hi - lo) / 3;

        if (cost(l) > cost(r))
            lo = l;
        else
            hi = r;
    }

    //print(lo, hi);

    ll ans = LLONG_MAX;
    for (int i = lo; i <= hi; ++i) {
        ckmin(ans, cost(i));
        //if (cost(i) == 0)
        //print(i);
    }

    print(ans);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    //int t; read(t);
    //while (t--)
    solve();
}
