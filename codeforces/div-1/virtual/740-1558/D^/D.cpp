#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template<class t> using oset = tree<t, null_type, less<t>, rb_tree_tag, tree_order_statistics_node_update>;

const int N = 2e5 + 69, MOD = 998'244'353;
int fact[N * 2];
int inv(int b, int e = MOD - 2) {
    int res = 1;
    for (; e; e >>= 1, b = 1LL * b * b % MOD) if (e & 1) res = 1LL * res * b % MOD;
    return res;
}
int nCr(int n, int r) {
    if (n < r) return 0;
    return 1LL * fact[n] * (1LL * inv(fact[r]) * inv(fact[n - r]) % MOD) % MOD;
}

int n, m, x, y[N];
oset<int> have;

void solve() {
    cin >> n >> m;

    for (int i = 0; i < m; ++i)
        cin >> x >> y[i];

    set<int> take;
    vector<int> rem;
    for (int i = m - 1; ~i; --i) {
        x = *have.find_by_order(y[i] - 1);

        have.erase(x);
        rem.push_back(x);

        x = *have.find_by_order(y[i] - 1);
        if (x <= n)
            take.insert(x);
    }

    cout << nCr(n * 2 - 1 - take.size(), n) << '\n';

    for (int i : rem)
        have.insert(i);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    fact[0] = 1;
    for (int i = 1; i < N * 2; ++i) {
        fact[i] = 1LL * fact[i - 1] * i % MOD;
        if (i < N)
            have.insert(i);
    }

    int t;
    cin >> t;
    while (t--)
        solve();
}

