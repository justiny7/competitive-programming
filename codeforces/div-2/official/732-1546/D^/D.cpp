#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1e5 + 69, MOD = 998'244'353;
ll fact[N];
ll binpow(ll b, ll e) {
    ll ret = 1;
    for (; e; (b *= b) %= MOD, e >>= 1)
        if (e & 1)
            (ret *= b) %= MOD;
    return ret;
}
ll nCr(int n, int r) {
    return fact[n] * binpow(fact[r] * fact[n - r] % MOD, MOD - 2) % MOD;
}

void solve() {
    int n; string s;
    cin >> n >> s;

    int ones = 0, zeros = 0, cur = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '1')
            ++cur;
        else {
            ones += cur / 2;
            ++zeros;
            cur = 0;
        }
    }
    ones += cur / 2;

    cout << nCr(ones + zeros, zeros) << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    fact[0] = 1;
    for (int i = 1; i < N; ++i)
        fact[i] = fact[i - 1] * i % MOD;

    int t; cin >> t;
    while (t--)
        solve();
}
