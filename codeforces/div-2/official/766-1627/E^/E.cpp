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
    int n, m, k;
    read(n, m, k);

    vector<ll> x(n);
    read(x);

    vector<set<int>> s_pts(n);
    vector<vector<int>> pts(n);
    vector<vector<array<ll, 4>>> ladders(n);
    while (k--) {
        int a, b, c, d, h;
        read(a, b, c, d, h);
        --a, --b, --c, --d;

        ladders[a].push_back({b, c, d, h});
        s_pts[a].insert(b);
        s_pts[c].insert(d);
    }

    s_pts[0].insert(0);
    s_pts[n - 1].insert(m - 1);

    for (int i = 0; i < n; ++i)
        for (int j : s_pts[i])
            pts[i].push_back(j);

    vector<map<ll, ll>> dp(n);
    dp[0][0] = 0;
    for (int i = 0; i < n; ++i) {
        vector<int> &here = pts[i];
        int sz = here.size();

        for (int j = 1; j < sz; ++j) {
            if (dp[i].count(here[j - 1])) {
                if (!dp[i].count(here[j]))
                    dp[i][here[j]] = LLONG_MAX;
                dp[i][here[j]] = min(dp[i][here[j]], dp[i][here[j - 1]] + x[i] * (here[j] - here[j - 1]));
            }
        }
        for (int j = sz - 2; j >= 0; --j) {
            if (dp[i].count(here[j + 1])) {
                if (!dp[i].count(here[j]))
                    dp[i][here[j]] = LLONG_MAX;
                dp[i][here[j]] = min(dp[i][here[j]], dp[i][here[j + 1]] + x[i] * (here[j + 1] - here[j]));
            }
        }

        for (auto [ind, tor, toc, health] : ladders[i]) {
            if (dp[i].count(ind)) {
                if (!dp[tor].count(toc))
                    dp[tor][toc] = LLONG_MAX;
                dp[tor][toc] = min(dp[tor][toc], dp[i][ind] - health);
            }
        }
    }

    if (dp[n - 1].count(m - 1))
        cout << dp[n - 1][m - 1] << '\n';
    else
        cout << "NO ESCAPE\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t; read(t);
    while (t--)
        solve();
}

