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
int n, ans[N];
vector<int> adj[N];
map<pair<int, int>, int> mp;

void solve() {
    read(n);
    for (int i = 1, u, v; i < n; ++i) {
        read(u, v);
        adj[u].push_back(v);
        adj[v].push_back(u);

        mp[make_pair(u, v)] = mp[make_pair(v, u)] = i - 1;
    }

    int c = 0;
    memset(ans, -1, sizeof(ans));
    for (int i = 1; i <= n; ++i) {
        if (adj[i].size() > 2) {
            ans[mp[make_pair(i, adj[i][0])]] = 0;
            ans[mp[make_pair(i, adj[i][1])]] = 1;
            ans[mp[make_pair(i, adj[i][2])]] = 2;
            c = 3;
            break;
        }
    }

    for (int i = 0; i < n - 1; ++i)
        if (ans[i] < 0)
            ans[i] = c++;

    for (int i = 0; i < n - 1; ++i)
        cout << ans[i] << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    //int t; read(t);
    //while (t--)
    solve();
}
