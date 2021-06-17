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

const int N = 5e5 + 69, L = 20;
int n, m, lift[N][L];

void solve() {
    read(n, m);

    memset(lift, -1, sizeof(lift));
    for (int i = 1; i <= n; ++i) {
        int l, r;
        read(l, r);
        ckmax(lift[l][0], r);
    }

    for (int i = 1; i < N; ++i)
        if (lift[i - 1][0] > i)
            ckmax(lift[i][0], lift[i - 1][0]);

    for (int i = 1; i < L; ++i)
        for (int j = 0; j < N; ++j)
            if (~lift[j][i - 1])
                lift[j][i] = lift[lift[j][i - 1]][i - 1];

    while (m--) {
        int l, r, ret = 0;
        read(l, r);

        for (int i = L - 1; ~i; --i)
            if (~lift[l][i] && lift[l][i] < r)
                l = lift[l][i], ret += (1 << i);

        cout << (~lift[l][0] ? ret + 1 : -1) << '\n';
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    //int t; read(t);
    //while (t--)
    solve();
}
