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

const int N = 501;
int n, k, dp[N], par[N];

int ask(vector<int> qu) {
    cout << "?";
    for (int i : qu)
        cout << " " << i;
    cout << endl;

    int ret; cin >> ret;
    return ret;
}

void solve() {
    read(n, k);

    memset(dp, -1, sizeof(dp));
    dp[0] = 0;
    queue<int> q;
    q.push(0);

    while (q.size()) {
        int v = q.front(); q.pop();

        //print(">", v, dp[v]);

        for (int i = 0; i <= min(k, v); ++i) { // i = how many to turn off
            int j = min(n - v, k - i); // how many to turn on

            int u = v - i + j;
            if (j + i == k && u >= 0 && u <= n && dp[u] < 0) {
                dp[u] = dp[v] + 1;
                par[u] = v;
                q.push(u);
            }
        }
    }

    if (dp[n] < 0)
        finish(-1);

    int v = n;
    vector<int> ops;
    while (v != 0) {
        ops.push_back(v);
        v = par[v];
    }

    reverse(all(ops));

    vector<int> cur(n);
    int ans = 0;

    for (int i : ops) {
        int here = accumulate(all(cur), 0);
        //print("?", cur);

        if (here > i) {
            int dif = here - i,
                on = (k - dif) / 2,
                off = k - on;

            //print("!", i, here, dif, on, off);

            vector<int> qu;
            for (int j = 0; j < n; ++j) {
                if (cur[j] && off > 0) {
                    --off;
                    qu.push_back(j + 1);
                }
                if (!cur[j] && on > 0) {
                    --on;
                    qu.push_back(j + 1);
                }
            }

            assert(!on && !off);

            for (int j : qu)
                cur[j - 1] ^= 1;

            ans ^= ask(qu);
        }
        else {
            int dif = i - here,
                off = (k - dif) / 2,
                on = k - off;

            vector<int> qu;
            for (int j = 0; j < n; ++j) {
                if (cur[j] && off > 0) {
                    --off;
                    qu.push_back(j + 1);
                }
                else if (!cur[j] && on > 0) {
                    --on;
                    qu.push_back(j + 1);
                }
            }

            for (int j : qu)
                cur[j - 1] ^= 1;

            ans ^= ask(qu);
        }
    }

    cout << "! " << ans << endl;
}

int main() {
    //cin.tie(0)->sync_with_stdio(0);

    //int t; read(t);
    //while (t--)
    solve();
}
