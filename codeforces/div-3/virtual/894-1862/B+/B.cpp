#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int &i : a)
        cin >> i;

    vector<int> ans = {a[0]};
    for (int i = 1; i < n; ++i) {
        if (a[i] < a[i - 1])
            ans.push_back(1);
        ans.push_back(a[i]);
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

