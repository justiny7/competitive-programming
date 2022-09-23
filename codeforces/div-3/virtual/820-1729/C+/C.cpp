#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s;
    cin >> s;

    int n = s.size();

    char l = min(s[0], s.back()), r = max(s[0], s.back());

    vector<pair<char, int>> w;
    for (int i = 0; i < n; ++i)
        if (l <= s[i] && s[i] <= r)
            w.push_back({s[i], i});

    sort(w.begin(), w.end());

    if (s[0] > s.back())
        reverse(w.begin(), w.end());

    int sz = w.size();
    for (int i = 1; i < sz; ++i) {
        if (w[i].second == 0) {
            swap(w[i], w[0]);
            break;
        }
    }
    for (int i = 0; i < sz - 1; ++i) {
        if (w[i].second == n - 1) {
            swap(w[i], w[sz - 1]);
            break;
        }
    }

    cout << abs(s.back() - s[0]) << " " << sz << '\n';
    for (auto [c, x] : w)
        cout << x + 1 << " ";
    cout << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--)
        solve();
}

