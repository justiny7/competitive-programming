#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n), srt;
    for (int &i : a)
        cin >> i;

    srt = a;
    sort(srt.begin(), srt.end());

    vector<array<int, 3>> ops;
    for (int i = 0; i < n - 1; ++i) {
        int targ = srt[i], ind = i;
        for (; ind < n; ++ind)
            if (a[ind] == targ)
                break;

        if (ind != i) {
            ops.push_back({i + 1, n, ind - i});
            rotate(a.begin() + i, a.begin() + ind, a.end());
        }
    }

    cout << ops.size() << '\n';
    for (auto [l, r, d] : ops)
        cout << l << " " << r << " " << d << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    int t;
    cin >> t;
    while (t--)
        solve();
}

