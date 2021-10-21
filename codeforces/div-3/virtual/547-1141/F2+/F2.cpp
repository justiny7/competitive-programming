#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n;
    cin >> n;

    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i)
        cin >> a[i], a[i] += a[i - 1];

    map<int, vector<array<int, 2>>> mp;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= i; ++j)
            mp[a[i] - a[j - 1]].push_back({j, i});

    vector<array<int, 2>> ans;
    for (auto [val, v] : mp) {
        vector<array<int, 2>> here;
        int rb = 0;
        for (auto [l, r] : v) {
            if (l > rb) {
                here.push_back({l, r});
                rb = r;
            }
        }

        if (here.size() > ans.size())
            swap(ans, here);
    }

    cout << ans.size() << '\n';
    for (auto [l, r] : ans)
        cout << l << " " << r << '\n';
}

