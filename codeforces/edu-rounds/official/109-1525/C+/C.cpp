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
template<class T> bool ckmin(T &a, const T b) { return (b < a ? a = b, 1 : 0); }
template<class T> bool ckmax(T &a, const T b) { return (a < b ? a = b, 1 : 0); }

using ll = long long;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

//Constants
const ll M = 1e9 + 7; //998244353;
const int dr[] = {1, 0, -1, 0}, dc[] = {0, 1, 0, -1};

//}}}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void solve() {
    int n; ll m;
    read(n, m);
    vector<int> orig(n);
    map<int, int> mp;
    vector<ll> ans(n, -1);
    vector<pair<ll, char>> a(n);
    for (int i = 0; i < n; ++i)
        read(a[i].first), orig[i] = a[i].first;
    for (int i = 0; i < n; ++i)
        read(a[i].second);
    sort(all(a));
    stack<int> st[2];
    set<int> alive;
    for (int i = 0; i < n; ++i) {
        alive.insert(i);
        mp[a[i].first] = i;
    }
    for (int i = 0; i < n; ++i) {
        int c = (a[i].first & 1);
        if (a[i].second == 'R')
            st[c].push(i);
        else if (st[c].size()) {
            alive.erase(st[c].top());
            alive.erase(i);
            ans[i] = ans[st[c].top()] = (a[i].first - a[st[c].top()].first) / 2;
            st[c].pop();
        }
    }
    vector<int> lf[2], rt[2];
    for (int i : alive) {
        //write(i, ' ');
        int c = (a[i].first & 1);
        if (a[i].second == 'L')
            lf[c].push_back(i);
        else
            rt[c].push_back(i);
    }
    //print();
    for (int t = 0; t < 2; ++t) {
        for (int i = 0; i + 1 < lf[t].size(); i += 2) {
            int u = lf[t][i], v = lf[t][i + 1];
            ans[u] = ans[v] = (a[u].first + a[v].first) / 2;
            alive.erase(u); alive.erase(v);
        }
        for (int i = rt[t].size() - 1; i - 1 >= 0; i -= 2) {
            int u = rt[t][i], v = rt[t][i - 1];
            ans[u] = ans[v] = (m * 2 - a[u].first - a[v].first) / 2;
            alive.erase(u); alive.erase(v);
        }
    }
    pair<int, int> oo = {-1, -1}, ee = {-1, -1};
    for (int i : alive) {
        if (a[i].first & 1) {
            if (a[i].second == 'L')
                oo.first = i;
            else
                oo.second = i;
        }
        else {
            if (a[i].second == 'L')
                ee.first = i;
            else
                ee.second = i;
        }
    }
    if (~oo.first && ~oo.second) {
        auto [u, v] = oo;
        ll dif = max(a[u].first, m - a[v].first);
        ll adif = abs(a[u].first - dif);
        ll bdif = abs(m - a[v].first - dif);
        ll ax = adif, bx = m - bdif;
        ans[u] = ans[v] = (bx - ax) / 2 + dif;
    }
    if (~ee.first && ~ee.second) {
        auto [u, v] = ee;
        ll dif = max(a[u].first, m - a[v].first);
        ll adif = abs(a[u].first - dif);
        ll bdif = abs(m - a[v].first - dif);
        ll ax = adif, bx = m - bdif;
        ans[u] = ans[v] = (bx - ax) / 2 + dif;
    }
    for (int i = 0; i < n; ++i)
        write(ans[mp[orig[i]]], " \n"[i == n - 1]);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; read(t);
    while (t--)
        solve();
}
