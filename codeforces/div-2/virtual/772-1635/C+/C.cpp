#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n;
    cin >> n;

    vector<ll> a(n);
    for (ll &i : a)
        cin >> i;

    if (is_sorted(a.begin(), a.end())) {
        cout << "0\n";
        return;
    }

    if (a[n - 2] > a[n - 1]) {
        cout << "-1\n";
        return;
    }

    vector<array<int, 3>> ops;
    for (int i = n - 3; ~i; --i) {
        ll here = min(a[i], a[i + 1] - a.back());
        if (here > a[i + 1]) {
            cout << "-1\n";
            return;
        }

        ops.push_back({i + 1, i + 2, n});
        a[i] = here;

        // for (int j : a)
            // cout << j << " "; cout << '\n';
    }

    cout << ops.size() << '\n';
    for (auto [x, y, z] : ops)
        cout << x << " " << y << " " << z << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--)
        solve();
}

