#include <bits/stdc++.h>
using namespace std;

//TEMPLATE {{{

//Macros
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

#define finish(...) return void(print(__VA_ARGS__))
#define uid(a, b) uniform_int_distribution<int>((a), (b))(rng)

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

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

//Constants
const ll M = 1e9 + 7; //998244353;
const int dr[] = {1, 0, -1, 0}, dc[] = {0, 1, 0, -1};

//}}}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int cmp(string s) {
    int ret = 0;
    for (int i = 0; i + 4 <= s.size(); ++i)
        ret += (s.substr(i, 4) == "haha");
    return ret;
}

struct dat {
    string b, e;
    ll val;

    dat() {}
    dat(string s) {
        int sz = s.size();
        b = s.substr(0, min(3, (int)sz));
        e = s.substr(sz - min(3, (int)sz));
        val = cmp(s);
    }
};

dat comb(dat a, dat b) {
    dat ret;
    string tot = a.e + b.b, bret = a.b + b.b, eret = a.e + b.e;
    //print(tot);
    ret.val = a.val + b.val + cmp(tot);
    ret.b = bret.substr(0, 3);
    ret.e = eret.substr(eret.size() - min((int)eret.size(), 3));
    return ret;
}

void solve() {
    int n; read(n);
    map<string, dat> mp;
    //map<string, string> mp2;

    while (n--) {
        string name, op;
        read(name, op);
        if (op == ":=") {
            string a; read(a);
            mp[name] = dat(a);
            //mp2[name] = a;
        }
        else {
            string a, b;
            read(a, op, b);
            mp[name] = comb(mp[a], mp[b]);
            //mp2[name] = mp2[a] + mp2[b];
        }

        //print(mp[name].b, mp[name].e, mp[name].val);
        //for (auto [x, y] : mp2)
        //print(x, ":", y);
        if (n == 0)
            print(mp[name].val);
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t; read(t);
    while (t--)
        solve();
}
