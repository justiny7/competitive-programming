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

string brute(string s) {
    string ret = s;
    int mx = INT_MAX, n = s.size();

    do {
        vector<int> p(n);
        for (int i = 1; i < n; ++i) {
            int j = p[i - 1];
            while (j > 0 && s[i] != s[j])
                j = p[j - 1];
            if (s[i] == s[j])
                ++j;
            p[i] = j;
        }

        //print(s);
        //print(p);
        if (mx == INT_MAX)
            mx = *max_element(all(p));
        else if (*max_element(all(p)) < mx) {
            mx = *max_element(all(p));
            ret = s;
        }
    } while (next_permutation(all(s)));

    return ret;
}

#define uid(a, b) uniform_int_distribution<int>((a), (b))(rng)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve() {
    string s; int n;
    read(s), n = s.size();
    /*
    n = uid(1, 8);
    s.resize(n);
    for (int i = 0; i < n; ++i)
        s[i] = char('a' + uid(0, 25));
    print(s);
    */
    sort(all(s));
    //print(brute(s));

    map<char, int> mp;
    bool f = 0;
    for (char c : s)
        ++mp[c];

    if (mp.size() == 1)
        finish(s);

    for (char c = 'a'; c <= 'z'; ++c) {
        if (mp.count(c) && mp[c] == 1) {
            write(c);
            for (char k : s)
                if (k != c)
                    write(k);
            finish();
        }
    }

    int scnt = mp.begin()->second;
    if (scnt == 1)
        print(s);
    else if (scnt + scnt - 2 <= n) {
        char sc = mp.begin()->first;

        mp[sc] -= 2;
        write(sc, sc);

        int j = 0;
        for (; j < n && s[j] == s[0]; ++j);
        for (; j < n; ++j) {
            write(s[j]);
            if (mp[sc]) {
                write(sc);
                --mp[sc];
            }
        }
        print();
    }
    else if (mp.size() > 2) {
        auto it = mp.begin();
        char sc = it->first;
        ++it;
        char tc = it->first;
        ++it;
        char nc = it->first;

        write(sc, tc);
        --mp[sc], --mp[tc];

        while (mp[sc]--)
            write(sc);
        write(nc);
        while (mp[tc]--)
            write(tc);

        int j = 0;
        bool fnc = 0;
        for (; j < n && (s[j] == sc || s[j] == tc); ++j);
        for (; j < n; ++j) {
            if (s[j] == nc && !fnc)
                fnc = 1;
            else
                write(s[j]);
        }

        print();
    }
    else {
        auto it = mp.begin();
        char sc = it->first;
        ++it;
        char tc = it->first;

        write(sc);
        --mp[sc];
        while (mp[tc]--)
            write(tc);
        while (mp[sc]--)
            write(sc);
        print();
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t; read(t);
    while (t--)
        solve();
}
