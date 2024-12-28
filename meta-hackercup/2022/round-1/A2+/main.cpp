#include <bits/stdc++.h>
using namespace std;

using ll = long long;

// Polynomial Hash {{{
#define uid(a, b) uniform_int_distribution<int>((a), (b))(rng)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int HASH_N = 5e5 + 69; // or whatever max size
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
    Hash(vector<ll> s) { init(s); }

    void init(vector<ll> s) {
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

void solve() {
    int n, k;
    cin >> n >> k;

    vector<ll> a(n), b(n);
    for (ll &i : a)
        cin >> i;
    for (ll &i : b)
        cin >> i;

    vector<ll> aa(a);
    for (int i : a)
        aa.push_back(i);

    Hash aah(aa), bh(b);
    int pos = -1;
    for (int i = 1; i < n; ++i) {
        if (bh.get(0, n) == aah.get(i, n)) {
            pos = i;
            break;
        }
    }

    bool same = (bh.get(0, n) == aah.get(0, n));
    if ((pos < 0 || k == 0) && !same) {
        cout << "NO\n";
        return;
    }

    if (n == 2) {
        if (same && (k % 2 == 0))
            cout << "YES\n";
        else if (pos == 1 && (k & 1))
            cout << "YES\n";
        else
            cout << "NO\n";
        return;
    }

    if (same && pos < 0) {
        if (k == 1)
            cout << "NO\n";
        else
            cout << "YES\n";
    } else if (same && pos >= 0) {
        cout << "YES\n";
    } else {
        assert(!same && pos >= 0);

        if (k == 0)
            cout << "NO\n";
        else
            cout << "YES\n";
    }
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

