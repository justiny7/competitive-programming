#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    map<int, int> cnt;
    for (int &i : a) {
        cin >> i;
        ++cnt[i];
    }

    for (auto [x, c] : cnt) {
        if (c * 2 >= n) {
            cout << "-1\n";
            return;
        }
    }

    vector<int> pos;
    set<int> seen;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            int dif = abs(a[i] - a[j]);
            if (seen.count(dif))
                continue;

            for (int i = 1; i * i <= dif; ++i) {
                if (dif % i == 0) {
                    pos.push_back(i);
                    if (dif / i != i)
                        pos.push_back(dif / i);
                }
            }
        }
    }

    int res = 1;
    for (int q : pos) {
        map<int, int> here;
        for (int x : a)
            ++here[(x % q + q) % q];

        for (auto [x, c] : here)
            if (c * 2 >= n)
                res = max(res, q);
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


