#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1e5 + 69, M = 1e9 + 7;
ll fact[N];

ll binpow(ll b, ll e) {
    ll ret = 1;
    for (; e; e >>= 1, (b *= b) %= M)
        if (e & 1)
            (ret *= b) %= M;
    return ret;
}
ll inv(ll x) {
    return binpow(x, M - 2);
}
ll nCr(ll n, ll r) {
    if (r < 0 || r > n)
        return 0;
    return (fact[n] * inv(fact[r]) % M) * inv(fact[n - r]) % M;
}

void solve() {
    ll n, k, ans = 1;
    cin >> n >> k;

    for (ll i = 1; i <= n; ++i) {
        ll here = nCr(n - (i - 1) * (k - 1), i);
        (here *= inv(nCr(n, i))) %= M;
        (ans += here) %= M;
    }

    cout << ans << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    fact[0] = 1;
    for (int i = 1; i < N; ++i)
        fact[i] = fact[i - 1] * i % M;

    int t; cin >> t;
    while (t--)
        solve();
}
