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

    vector<int> dif;
    for (int i = 0; i < n; ++i)
        dif.push_back(b[i] - a[i]);

    sort(dif.begin(), dif.end());

    int l = 0, r = n - 1, res = 0;
    while (l < r) {
        while (l < r && dif[r] + dif[l] < 0)
            ++l;

        if (l >= r)
            break;

        ++res;
        --r, ++l;
    }

    cout << res << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--)
        solve();
}

