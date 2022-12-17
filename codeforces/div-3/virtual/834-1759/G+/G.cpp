#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    set<int> have;
    for (int i = 1; i <= n; ++i)
        have.insert(i);

    vector<int> a(n / 2), res(n);
    bool f = 0;
    for (int i = 1; i < n; i += 2) {
        cin >> a[i / 2];
        res[i] = a[i / 2];

        if (have.count(a[i / 2]))
            have.erase(a[i / 2]);
        else
            f = 1;
    }

    if (f) {
        cout << "-1\n";
        return;
    }

    for (int i = n - 1; i >= 0; i -= 2) {
        auto need = have.upper_bound(res[i]);
        if (need == have.begin()) {
            cout << "-1\n";
            return;
        }

        --need;
        if (*need < res[i]) {
            res[i - 1] = *need;
            have.erase(need);
        } else {
            cout << "-1\n";
            return;
        }
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

