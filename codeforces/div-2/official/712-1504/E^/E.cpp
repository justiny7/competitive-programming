#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1e5 + 1;
int n; ll ans;
pair<ll, ll> a[N];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i].first >> a[i].second;
        ans += a[i].second;
    }
    sort(a, a + n);
    ll cur = a[0].first + a[0].second;
    for (int i = 1; i < n; ++i) {
        ans += max(0LL, a[i].first - cur);
        cur = max(cur, a[i].first + a[i].second);
    }
    cout << ans << '\n';
}
