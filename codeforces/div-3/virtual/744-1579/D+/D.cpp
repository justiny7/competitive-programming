#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    priority_queue<array<int, 2>> pq;
    for (int i = 1; i <= n; ++i) {
        int x;
        cin >> x;

        if (x)
            pq.push({x, i});
    }

    vector<array<int, 2>> ans;
    while (pq.size() > 1) {
        auto [a, i] = pq.top();
        pq.pop();
        auto [b, j] = pq.top();
        pq.pop();

        ans.push_back({i, j});
        if (a > 1)
            pq.push({a - 1, i});
        if (b > 1)
            pq.push({b - 1, j});
    }

    cout << ans.size() << '\n';
    for (auto [a, b] : ans)
        cout << a << " " << b << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--)
        solve();
}

