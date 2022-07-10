#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    
    vector<int> a(n);
    for (int &i : a)
        cin >> i, i *= 2;

    sort(a.begin(), a.end());

    int res = 0;
    while (m > 1) {
        res += a.back();
        a.pop_back();
        --m;
    }

    int sz = a.size();

    if (sz & 1)
        res += a[sz / 2];
    else
        res += (a[sz / 2] + a[sz / 2 - 1]) / 2;

    if (res & 1)
        cout << res / 2 << ".5\n";
    else
        cout << res / 2 << ".0\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    for (int tc = 1; tc <= t; ++tc) {
        cout << "Case #" << tc << ": ";
        solve();
    }
}

