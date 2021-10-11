#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<array<int, 5>> v(n);
    for (auto &a : v)
        for (int &i : a)
            cin >> i;

    for (int i = 0; i < 5; ++i) {
        for (int j = i + 1; j < 5; ++j) {
            bool f = 0;
            int ic = 0, jc = 0, ijc = 0;

            for (auto a : v) {
                if (a[i] && a[j])
                    ++ijc;
                else if (a[i])
                    ++ic;
                else if (a[j])
                    ++jc;
                else
                    f = 1;
            }

            if (f)
                continue;
            if (ic * 2 > n || jc * 2 > n)
                continue;

            cout << "YES\n";
            return;
        }
    }

    cout << "NO\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--)
        solve();
}

