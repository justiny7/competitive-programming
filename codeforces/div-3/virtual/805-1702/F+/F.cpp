#include <bits/stdc++.h>
using namespace std;

int msb(int x) {
    int res = 0;
    while (x)
        x /= 2, ++res;
    return res;
}

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int &i : a) {
        cin >> i;

        while (i % 2 == 0)
            i /= 2;
    }

    sort(a.rbegin(), a.rend());

    multiset<int> ms;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;

        while (msb(x) < 30) {
            x *= 2;
            // cout << x << " " << __builtin_popcount(x) << '\n';
        }

        ms.insert(x);
    }

    int cur = 30;
    for (int i = 0; i < n; ++i) {
        int here = a[i];
        while (msb(here) < cur) {
            // cout << msb(here) << " " << cur << '\n';
            --cur;

            multiset<int> tmp;
            for (int x : ms)
                tmp.insert(x / 2);

            ms.swap(tmp);
        }

        if (ms.count(here))
            ms.erase(ms.find(here));
        else {
            cout << "NO\n";
            return;
        }
    }

    cout << "YES\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--)
        solve();
}


