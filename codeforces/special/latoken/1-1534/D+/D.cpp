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

int n;

vector<int> ask(int v) {
    cout << "? " << v << endl;
    vector<int> ret(n);
    read(ret);
    return ret;
}

void solve() {
    read(n);

    set<pair<int, int>> ans;

    vector<int> o, e, d = ask(1);
    for (int i = 0; i < n; ++i) {
        if (d[i] == 1)
            ans.emplace(1, i + 1);
        if (d[i] & 1)
            o.push_back(i + 1);
        else if (i != 0)
            e.push_back(i + 1);
    }

    //print(o);
    //print(e);

    if (o.size() > e.size())
        swap(o, e);

    auto it = find(all(o), 1);
    if (it != o.end())
        o.erase(it);

    for (int i : o) {
        d = ask(i);
        for (int j = 0; j < n; ++j) {
            if (d[j] == 1)
                ans.emplace(min(i, j + 1), max(i, j + 1));
        }
    }

    cout << "!" << endl;
    for (auto [u, v] : ans)
        cout << u << " " << v << endl;
}

int main() {
    //cin.tie(0)->sync_with_stdio(0);

    //int t; read(t);
    //while (t--)
    solve();
}
