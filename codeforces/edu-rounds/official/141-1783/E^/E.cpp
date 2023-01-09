#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n), b(n);
    for (int &i : a)
        cin >> i;
    for (int &i : b)
        cin >> i;

    vector<int> seg(n + 1);
    for (int i = 0; i < n; ++i)
        if (a[i] > b[i])
            ++seg[b[i]], --seg[a[i]];

    for (int i = 1; i <= n; ++i)
        seg[i] += seg[i - 1];

    vector<int> res;
    for (int i = 1; i <= n; ++i) {
        bool f = 1;
        for (int j = i; j <= n; j += i)
            f &= !seg[j];

        if (f)
            res.push_back(i);
    }

    cout << res.size() << '\n';
    for (int i : res)
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

