#include <bits/stdc++.h>
using namespace std;

using ll = long long;

// Polynomial Hash {{{
#define uid(a, b) uniform_int_distribution<int>((a), (b))(rng)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int HASH_N = 1e6 + 69; // or whatever max size
const ll MD[2] = {(ll)1e9 + 7, (ll)1e9 + 9}, B = uid(501, MD[0] - 2);
ll p[2][HASH_N];

// Call prep_hash() before creating any hashes
void prep_hash() {
    for (int c = 0; c < 2; ++c) {
        p[c][0] = 1;
        for (int i = 1; i < HASH_N; ++i)
            p[c][i] = p[c][i - 1] * B % MD[c];
    }
}

struct Hash {
    vector<ll> hsh[2];
    Hash() {}
    Hash(string s) { init(s); }

    void init(string s) {
        int sz = s.size();
        for (int c = 0; c < 2; ++c) {
            hsh[c].resize(sz + 1);
            for (int i = 0; i < sz; ++i)
                hsh[c][i + 1] = (hsh[c][i] * B + s[i]) % MD[c];
        }
    }
    array<ll, 2> get(int st, int len) {
        array<ll, 2> ret;
        for (int c = 0; c < 2; ++c)
            ret[c] = (hsh[c][st + len] - hsh[c][st] * p[c][len] % MD[c] + MD[c]) % MD[c];
        return ret;
    }
};
// }}}


vector<ll> cur1 = {0}, cur2 = {0};
void dfs(vector<vector<pair<int, char>>> &adj, map<pair<ll, ll>, ll> &mp, int v = 1) {
    ++mp[make_pair(cur1.back(), cur2.back())];

    for (auto [u, c] : adj[v]) {
        cur1.push_back((cur1.back() * B + c) % MD[0]);
        cur2.push_back((cur2.back() * B + c) % MD[1]);
        dfs(adj, mp, u);
        cur1.pop_back();
        cur2.pop_back();
    }
}

void solve() {
    int n;
    cin >> n;

    map<pair<ll, ll>, ll> mp;
    for (int i = 0; i < n; ++i) {
        int sz;
        cin >> sz;

        vector<vector<pair<int, char>>> adj(sz + 1);
        for (int i = 2; i <= sz; ++i) {
            int p;
            char c;
            cin >> p >> c;
            adj[p].push_back({i, c});
        }

        dfs(adj, mp);
    }

    ll res = 0;
    ll all = 1LL * n * (n - 1) * (n - 2) / 6;
    for (auto [s, c] : mp) {
        ll no = n - c;
        ll cnt = 1LL * no * (no - 1) * (no - 2) / 6;
        res += all - cnt;
    }

    cout << res << '\n';
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    prep_hash();

    int t;
    cin >> t;
    for (int tc = 1; tc <= t; ++tc) {
        cout << "Case #" << tc << ": ";
        solve();
    }
}

