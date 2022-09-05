#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, d;
    cin >> n >> d;

    vector<int> a = {0};
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        a.push_back(x);
    }

    multiset<int> gaps;
    for (int i = 1; i <= n; ++i)
        gaps.insert(a[i] - a[i - 1] - 1);

    int res = *gaps.begin();
    for (int i = 1; i < n; ++i) {
        gaps.erase(gaps.find(a[i] - a[i - 1] - 1));
        gaps.erase(gaps.find(a[i + 1] - a[i] - 1));
        gaps.insert(a[i + 1] - a[i - 1] - 1);

        int lg = *prev(gaps.end());
        gaps.erase(prev(gaps.end()));

        gaps.insert(lg / 2);
        gaps.insert(lg / 2 + ((lg & 1) ? 0 : -1));

        res = max(res, *gaps.begin());

        gaps.erase(gaps.find(lg / 2));
        gaps.erase(gaps.find(lg / 2 + ((lg & 1) ? 0 : -1)));

        gaps.insert(lg);

        gaps.erase(gaps.find(a[i + 1] - a[i - 1] - 1));
        gaps.insert(a[i + 1] - a[i] - 1);
        gaps.insert(a[i] - a[i - 1] - 1);
    }

    if (a.back() != d) {
        for (int i = 1; i < n; ++i) {
            gaps.erase(gaps.find(a[i] - a[i - 1] - 1));
            gaps.erase(gaps.find(a[i + 1] - a[i] - 1));
            gaps.insert(a[i + 1] - a[i - 1] - 1);

            gaps.insert(d - a.back() - 1);

            res = max(res, *gaps.begin());

            gaps.erase(gaps.find(d - a.back() - 1));

            gaps.erase(gaps.find(a[i + 1] - a[i - 1] - 1));
            gaps.insert(a[i + 1] - a[i] - 1);
            gaps.insert(a[i] - a[i - 1] - 1);
        }

        gaps.erase(gaps.find(a[n] - a[n - 1] - 1));
        gaps.insert(d - a[n - 1] - 1);

        res = max(res, *gaps.begin());
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

