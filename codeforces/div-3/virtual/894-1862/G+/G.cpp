#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    multiset<int> ms, gaps;
    for (int &i : a) {
        cin >> i;
        ms.insert(i);
    }

    if (n == 1) {
        int q;
        cin >> q;
        while (q--) {
            int i, x;
            cin >> i >> x;
            cout << x << " ";
        }
        cout << '\n';
        return;
    }

    for (auto it = next(ms.begin()); it != ms.end(); ++it)
        gaps.insert(*it - *prev(it));

    int q;
    cin >> q;
    while (q--) {
        int i, x;
        cin >> i >> x, --i;

        auto it = ms.find(a[i]);
        if (it != ms.begin() && next(it) != ms.end())
            gaps.insert(*next(it) - *prev(it));
        if (it != ms.begin())
            gaps.erase(gaps.find(*it - *prev(it)));
        if (next(it) != ms.end())
            gaps.erase(gaps.find(*next(it) - *it));
        ms.erase(it);

        auto nit = ms.insert(x);
        if (nit != ms.begin() && next(nit) != ms.end())
            gaps.erase(gaps.find(*next(nit) - *prev(nit)));
        if (nit != ms.begin())
            gaps.insert(*nit - *prev(nit));
        if (next(nit) != ms.end())
            gaps.insert(*next(nit) - *nit);

        a[i] = x;

        cout << (*ms.rbegin() + *gaps.rbegin()) << " ";
    }

    cout << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--)
        solve();
}

