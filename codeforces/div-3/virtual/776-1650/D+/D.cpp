#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int &i : a)
        cin >> i, --i;

    vector<int> res(n);
    for (int i = n - 1; ~i; --i) {
        auto it = find(a.begin(), a.end(), i);
        assert(it != a.end());

        int mv = (it - a.begin() + 1) % (i + 1);
        res[i] = mv;

        rotate(a.begin(), a.begin() + mv, a.begin() + i + 1);
        // for (int j = 0; j < n; ++j)
            // cout << a[j] << " \n"[j == n - 1];
    }

    for (int i = 0; i < n; ++i)
        cout << res[i] << " \n"[i == n - 1];
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--)
        solve();
}

