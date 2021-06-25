#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 2e5 + 69, M = 998244353;
int n, k, a[N], pos[N];
ll fact[N * 2];

ll binpow(ll b, ll e) {
    ll ret = 1;
    for (; e; (b *= b) %= M, e >>= 1)
        if (e & 1)
            (ret *= b) %= M;
    return ret;
}
ll inv(ll x) {
    return binpow(x, M - 2);
}
ll nCr(int nn, int rr) {
    return (fact[nn] * inv(fact[rr]) % M) * inv(fact[nn - rr]) % M;
}

int main() {
    fact[0] = 1;
    for (int i = 1; i < N * 2; ++i)
        fact[i] = (fact[i - 1] * (ll)i) % M;

    cin.tie(0)->sync_with_stdio(0);

    cin >> n >> k, --k;
    for (int i = 0; i < n; ++i)
        cin >> a[i], pos[a[i]] = i;
    pos[n] = -1;

    int mn = 0;
    for (int i = 0; i < n - 1; ++i)
        if (pos[a[i] + 1] > pos[a[i + 1] + 1])
            ++mn;

    cout << (k < mn ? 0 : nCr(n + k - mn, n)) << '\n';
}
