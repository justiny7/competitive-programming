#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<int> cnt(n + 1), res(n + 1);
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        
        if (x <= n)
            ++cnt[x];
    }

    for (int i = 1; i <= n; ++i)
        for (int j = 0; j <= n; j += i)
            if (j)
                res[j] += cnt[i];

    cout << *max_element(res.begin(), res.end()) << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--)
        solve();
}

