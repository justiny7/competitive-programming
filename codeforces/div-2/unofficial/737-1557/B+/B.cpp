#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (int &i : a)
        cin >> i;

    vector<int> srt(a);
    sort(srt.begin(), srt.end());

    int c = 0, ptr = 0;
    for (int i = 1; i < n; ++i) {
        auto it = lower_bound(srt.begin(), srt.end(), a[i]);
        if (it == srt.begin() || *(--it) != a[i - 1])
            ++c;
    }

    cout << (c < k ? "Yes" : "No") << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--)
        solve();
}

