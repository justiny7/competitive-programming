#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 169;
int n; ll k, ans, a[N];
vector<ll> todo;

void check(ll x) {
    ll sum = 0;
    for (int i = 0; i < n; ++i)
        sum += (a[i] + x - 1) / x;

    if (sum * x <= k)
        ans = max(ans, k / sum);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        cin >> a[i], k += a[i];
        for (ll d = 1; d * d <= a[i]; ++d) {
            todo.push_back(d);
            todo.push_back((a[i] + d - 1) / d);
        }
    }

    sort(todo.begin(), todo.end());
    todo.erase(unique(todo.begin(), todo.end()), todo.end());

    for (ll d : todo)
        check(d);

    cout << ans << '\n';
}
