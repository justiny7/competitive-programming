#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n;
    cin >> n;

    vector<int> a(n);
    for (int &i : a)
        cin >> i;

    multiset<int> ms;
    for (int i : a)
        ms.insert(i);

    int res = INT_MAX;
    auto test = [&](int i, int shots) {
        ms.erase(ms.find(a[i]));
        if (i)
            ms.erase(ms.find(a[i - 1]));
        if (i + 1 < n)
            ms.erase(ms.find(a[i + 1]));

        ms.insert(max(0, a[i] - shots * 2));
        if (i)
            ms.insert(max(0, a[i - 1] - shots));
        if (i + 1 < n)
            ms.insert(max(0, a[i + 1] - shots));

        res = min(res, shots + (*next(ms.begin()) + 1) / 2);

        ms.erase(ms.find(max(0, a[i] - shots * 2)));
        if (i)
            ms.erase(ms.find(max(0, a[i - 1] - shots)));
        if (i + 1 < n)
            ms.erase(ms.find(max(0, a[i + 1] - shots)));

        ms.insert(a[i]);
        if (i)
            ms.insert(a[i - 1]);
        if (i + 1 < n)
            ms.insert(a[i + 1]);
    };

    for (int i = 0; i < n; ++i) {
        test(i, (a[i] + 1) / 2);
        if (i)
            test(i, a[i - 1]);
        if (i + 1 < n)
            test(i, a[i + 1]);
    }

    for (int i = 1; i < n; ++i) {
        int l = min(a[i - 1], a[i]), r = max(a[i - 1], a[i]);

        int shots = r - l;
        r -= shots * 2, l -= shots;

        if (l > 0 && r > 0)
            shots += (l + r + 2) / 3;

        res = min(res, shots);
    }

    cout << res << '\n';
}

