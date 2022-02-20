#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int &i : a)
        cin >> i;

    vector<int> pos;
    for (int i = 1; i < n - 1; ++i)
        if (a[i] > a[i - 1] && a[i] > a[i + 1])
            pos.push_back(i);

    int res = 0;
    for (int i = 0; i < pos.size(); ++i) {
        ++res;
        if (i + 1 < pos.size() && pos[i] == pos[i + 1] - 2) {
            a[pos[i] + 1] = max(a[pos[i]], a[pos[i + 1]]);
            ++i;
        } else {
            a[pos[i] + 1] = a[pos[i]];
        }
    }

    cout << res << '\n';
    for (int i = 0; i < n; ++i)
        cout << a[i] << " \n"[i == n - 1];
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--)
        solve();
}

