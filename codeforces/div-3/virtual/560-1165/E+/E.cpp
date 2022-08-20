#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const ll MOD = 998'244'353;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n;
    cin >> n;

    vector<ll> a(n), b(n);
    for (ll &i : a)
        cin >> i;
    for (ll &i : b)
        cin >> i;

    for (int i = 0; i < n; ++i)
        a[i] *= 1LL * (i + 1) * (n - i);

    sort(a.begin(), a.end());
    sort(b.rbegin(), b.rend());

    ll res = 0;
    for (int i = 0; i < n; ++i)
        (res += (a[i] % MOD * b[i]) % MOD) %= MOD;

    cout << res << '\n';
}

