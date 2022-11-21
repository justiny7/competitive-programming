#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int &i : a)
        cin >> i;

    int res = n;
    for (int i = 1; i <= n; ++i) {
        int need = 0;
        for (int j = 0; j < i; ++j)
            need += a[j];

        int here = i, cur = 0, lst = i;
        bool f = 0;
        for (int j = i; j < n; ++j) {
            if (cur + a[j] > need) {
                f = 1;
                break;
            }

            cur += a[j];
            if (cur == need) {
                cur = 0;
                here = max(here, j - lst + 1);
                lst = j + 1;
            }
        }

        if (!f && !cur)
            res = min(res, here);
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

