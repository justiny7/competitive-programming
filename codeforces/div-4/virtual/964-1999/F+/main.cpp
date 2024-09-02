#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const ll MOD = 1e9 + 7;
const int N = 2e5 + 5;
ll fact[N];

ll binpow(ll b, ll e) {
    ll res = 1;
    for (; e > 0; e >>= 1, (b *= b) %= MOD) {
        if (e & 1) {
            (res *= b) %= MOD;
        }
    }
    return res;
}
ll inv(ll x) {
    return binpow(x, MOD - 2);
}
ll nCk(ll n, ll k) {
    if (n < k) {
        return 0;
    }
    return (fact[n] * inv(fact[k]) % MOD) * inv(fact[n - k]) % MOD;
}

void solve() {
    int n, k;
    cin >> n >> k;

    int o = 0, e = 0;
    while (n--) {
        int x;
        cin >> x;

        o += (x == 1);
        e += (x == 0);
    }

    ll res = 0;
    for (int i = (k + 1) / 2; i <= k; i++) {
        int j = k - i;
        (res += nCk(o, i) * nCk(e, j) % MOD) %= MOD;
    }

    cout << res << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    fact[0] = 1;
    for (int i = 1; i < N; i++) {
        fact[i] = (fact[i - 1]) * i % MOD;
    }

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}

