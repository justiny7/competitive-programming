#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll binpow(ll b, ll e, ll MOD) {
    ll ret = 1;
    for (; e; (b *= b) %= MOD, e >>= 1)
        if (e & 1)
            (ret *= b) %= MOD;
    return ret;
}

const int MD = 1e9 + 7;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n;
    cin >> n;

    long long cnt = (binpow(2, n, MD - 1) - 2 + MD - 1) % (MD - 1);
    cout << (6LL * binpow(4, cnt, MD)) % MD << '\n';
}

