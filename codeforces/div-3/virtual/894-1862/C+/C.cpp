#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int &i : a)
        cin >> i;

    vector<int> hor = {1};
    for (int i = 1; i < n; ++i) {
        if (a[i] != a[i - 1])
            hor.push_back(1);
        else
            ++hor.back();
    }

    vector<int> ver = {a.back()};
    for (int i = n - 2; i >= 0; --i) {
        if (a[i] - a[i + 1] != 0)
            ver.push_back(a[i] - a[i + 1]);
    }

    cout << (hor == ver ? "YES" : "NO") << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--)
        solve();
}

