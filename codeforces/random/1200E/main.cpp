// Hash template testing
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Poly Hash {{{
#define uid(a, b) uniform_int_distribution<int>((a), (b))(rng)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = 1e6 + 69; // or whatever N
const ll MD[2] = {1000000007, 1000000009}, B = uid(501, MD[0] - 2);
ll p[2][N], inv[2][N];

ll binpow(ll b, ll e, int MOD) {
    ll ret = 1;
    for (; e; (b *= b) %= MOD, e >>= 1)
        if (e & 1)
            (ret *= b) %= MOD;
    return ret;
}

// Call prep() before creating any hashes
void prep() {
    for (int c = 0; c < 2; ++c) {
        p[c][0] = inv[c][0] = 1;
        for (int i = 1; i < N; ++i) {
            p[c][i] = p[c][i - 1] * B % MD[c];
            inv[c][i] = binpow(p[c][i], MD[c] - 2, MD[c]);
        }
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
                hsh[c][i + 1] = (hsh[c][i] + s[i] * p[c][i]) % MD[c];
        }
    }
    array<ll, 2> get(int st, int len) {
        array<ll, 2> ret;
        for (int c = 0; c < 2; ++c)
            ret[c] = (((hsh[c][st + len] - hsh[c][st]) * inv[c][st] % MD[c]) + MD[c]) % MD[c];
        return ret;
    }
};
// }}}

int n;
string ans;

int main() {
    prep();

    cin.tie(0)->sync_with_stdio(0);

    cin >> n;
    while (n--) {
        string s; cin >> s;

        int sz = min(s.size(), ans.size()), st = 0;
        if (sz > 0) {
            Hash h1(ans.substr(ans.size() - sz)), h2(s.substr(0, sz));
            for (int i = sz; i; --i) {
                if (h1.get(sz - i, i) == h2.get(0, i)) {
                    st = i;
                    break;
                }
            }
        }

        for (int i = st; i < s.size(); ++i)
            ans += s[i];
    }

    cout << ans << '\n';
}
