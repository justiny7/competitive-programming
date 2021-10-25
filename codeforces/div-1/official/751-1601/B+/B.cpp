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

const int N = 3e5 + 69;
int n, a[N], b[N], par[N];
bool vis[N];

void solve() {
    read(n);
    
    for (int i = 1; i <= n; ++i)
        read(a[i]);
    for (int i = 1; i <= n; ++i) {
        read(b[i]);
    }

    set<int, greater<>> s;
    for (int i = 0; i <= n; ++i)
        s.insert(i);

    queue<int> q;
    q.push(n);
    while (q.size() && s.size()) {
        int v = q.front();
        q.pop();

        if (v == 0) {
            vector<int> res;
            while (v != n) {
                res.push_back(v);
                v = par[v];
            }

            reverse(all(res));
            print(res.size());
            print(res);
            return;
        }

        int o = v;
        v += b[v];

        // cout << "sz: " << s.size() << '\n';

        auto it = s.upper_bound(v);
        if (it == s.end())
            continue;

        while (s.size() && it != s.end() && *it >= v - a[v]) {
            par[*it] = o;
            q.push(*it);
            ++it;
            s.erase(prev(it));
        }
    }

    cout << "-1\n";
}

int main() {
    // cin.tie(0)->sync_with_stdio(0);

    // int t; read(t);
    // while (t--)
        solve();
}

