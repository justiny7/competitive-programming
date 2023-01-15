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
int n, st, en;
int a[N], dist[N], par[N];

int spf[N];
void sieve() {
    memset(spf, -1, sizeof(spf));

    for (ll i = 2; i < N; ++i)
        if (spf[i] < 0)
            for (ll j = i; j < N; j += i)
                if (spf[j] < 0)
                    spf[j] = i;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    read(n);

    for (int i = 1; i <= n; ++i)
        read(a[i]);

    read(st, en);

    if (st == en) {
        print(1);
        print(st);
        return 0;
    }

    sieve();

    set<int> nums[N], primes[N];
    for (int i = 1; i <= n; ++i) {
        int x = a[i];
        while (x > 1) {
            primes[i].insert(spf[x]);
            x /= spf[x];
        }

        for (int j : primes[i])
            nums[j].insert(i);
    }

    memset(dist, -1, sizeof(dist));
    queue<int> q;
    q.push(st);
    dist[st] = 1;
    while (q.size()) {
        int v = q.front();
        q.pop();

        set<int> rem = {v};
        for (int p : primes[v]) {
            for (int u : nums[p]) {
                if (!rem.count(u)) {
                    assert(dist[u] == -1);
                    dist[u] = dist[v] + 1;
                    par[u] = v;
                    q.push(u);
                    rem.insert(u);
                }
            }
        }

        for (int u : rem)
            for (int q : primes[u])
                nums[q].erase(u);
    }

    print(dist[en]);
    if (~dist[en]) {
        vector<int> res;
        int x = en;
        while (x != st) {
            res.push_back(x);
            x = par[x];
        }
        res.push_back(st);

        reverse(all(res));
        for (int i : res)
            write(i, ' ');
        print();
    }
}

