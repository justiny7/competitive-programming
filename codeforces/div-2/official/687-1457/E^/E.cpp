#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int N = 5e5 + 69;
int n, k;
ll ans, c[N];
priority_queue<ll> pq;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> n >> k;

    for (int i = 0; i <= k; ++i)
        pq.push(0);

    for (int i = 0; i < n; ++i)
        cin >> c[i];

    sort(c, c + n);

    for (int i = n - 1; ~i; --i) {
        ll cur = pq.top(); pq.pop();
        ans += cur;
        pq.push(cur + c[i]);
    }

    cout << ans << '\n';
}

