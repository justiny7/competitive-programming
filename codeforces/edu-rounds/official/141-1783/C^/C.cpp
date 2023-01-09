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
    int n, m;
    read(n, m);

    vector<int> a(n);
    read(a);

    vector<array<int, 2>> pos(n);
    for (int i = 0; i < n; ++i)
        pos[i] = {a[i], i};

    sort(all(pos), [&](array<int, 2> x, array<int, 2> y) {
        if (x[0] != y[0])
            return x[0] < y[0];
        return x[1] > y[1];
    });

    int cur = 0;
    set<int> have;
    for (int i = 0; i < n; ++i) {
        if (cur + pos[i][0] > m)
            break;

        cur += pos[i][0];
        have.insert(pos[i][1]);
    }

    int score = have.size();
    for (int i = n - 1; ~i; --i) {
        int here = i + 1;
        int rem = -1;
        if (have.count(i))
            --here;
        else if (score && cur - pos[score - 1][0] + a[i] <= m) {
            --here;
            have.erase(pos[score - 1][1]);
            have.insert(i);
            rem = pos[score - 1][1];
        }

        if (here <= score) {
            vector<int> scores;
            for (int i = 0; i < n; ++i)
                scores.push_back(i + !have.count(i));
            sort(all(scores));
            int res = 1;
            while (here < scores.back()) {
                scores.pop_back();
                ++res;
            }
            print(res);
            return;
        }

        if (~rem) {
            have.erase(i);
            have.insert(rem);
        }
    }

    print(n + 1);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t; read(t);
    while (t--)
        solve();
}

