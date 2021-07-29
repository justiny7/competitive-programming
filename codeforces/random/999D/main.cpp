#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int N = 2e5 + 69;
ll n, m, targ, a[N];
vector<ll> cnt[N];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> n >> m, targ = n / m;

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        cnt[a[i] % m].push_back(i);
    }

    ll ans = 0;
    vector<ll> have;
    for (int t = 0; t < 2; ++t) {
        for (int i = 0; i < m; ++i) {
            while (cnt[i].size() > targ) {
                have.push_back(cnt[i].back());
                cnt[i].pop_back();
            }
            while (cnt[i].size() < targ && have.size()) {
                ll cur = have.back();
                have.pop_back();

                cnt[i].push_back(cur);
                ll add = (i - a[cur] % m + m) % m;
                ans += add, a[cur] += add;
            }
        }
    }

    cout << ans << '\n';
    for (int i = 0; i < n; ++i)
        cout << a[i] << " \n"[i == n - 1];
}

