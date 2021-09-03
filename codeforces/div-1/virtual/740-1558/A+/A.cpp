#include <bits/stdc++.h>
using namespace std;

void solve() {
    int a, b, n;
    cin >> a >> b, n = a + b;

    set<int> ans;
    for (int t = 0; t < 2; ++t) {
        for (int j = max(a + n / 2, b + (n + 1) / 2) - n; j <= min(a, n / 2) + min(b, (n + 1) / 2); j += 2)
            ans.insert(j);

        swap(a, b);
    }

    cout << ans.size() << '\n';
    for (int i : ans)
        cout << i << " ";
    cout << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--)
        solve();
}

