#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<int> res(n);
    vector<int> epos;
    for (int i = 0; i + 1 < n; i += 2)
        epos.push_back(i);

    for (int i = 0; i < n / 2; ++i)
        res[i * 2] = res[i * 2 + 1] = i + 1;

    for (int i = 0; i + 1 < epos.size(); i += 2) {
        res[epos[i]] ^= (1 << 30);
        res[epos[i + 1]] ^= (1 << 30);
    }

    if (epos.size() & 1) {
        if (n & 1) {
            res[n - 1] ^= (1 << 29);
            res[n - 3] ^= (1 << 29);
        } else {
            res[n - 2] ^= (1 << 29);
            res[n - 4] ^= (1 << 29);
        }
    }

    int esum = 0, osum = 0;
    for (int i = 0; i < n; ++i) {
        if (i & 1)
            osum ^= res[i];
        else
            esum ^= res[i];
    }

    assert(esum == osum);

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

