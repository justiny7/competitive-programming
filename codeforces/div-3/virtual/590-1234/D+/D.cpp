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

const int N = 1e5 + 69;
struct BIT {
    int bit[N];
    BIT() {
        memset(bit, 0, sizeof(bit));
    }

    void upd(int i, int x) {
        for (++i; i < N; i += i & -i)
            bit[i] += x;
    }
    int query(int i) {
        int ret = 0;
        for (++i; i; i -= i & -i)
            ret += bit[i];
        return ret;
    }
    int query(int l, int r) {
        return query(r) - query(l - 1);
    }
} ft[26];

void solve() {
    string s; int q, n;
    read(s, q);
    n = s.size();

    for (int i = 0; i < n; ++i)
        ft[s[i] - 'a'].upd(i + 1, 1);

    while (q--) {
        int t; read(t);

        if (t & 1) {
            int i; char c;
            read(i, c);

            ft[s[i - 1] - 'a'].upd(i, -1);
            ft[(s[i - 1] = c) - 'a'].upd(i, 1);
        }
        else {
            int l, r, ret = 0;
            read(l, r);

            for (int i = 0; i < 26; ++i)
                ret += (ft[i].query(l, r) > 0);

            print(ret);
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    //int t; read(t);
    //while (t--)
    solve();
}
