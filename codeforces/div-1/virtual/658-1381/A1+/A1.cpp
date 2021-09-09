#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    string s, t;
    cin >> n >> s >> t;

    vector<int> ops;
    for (int i = 0; i < n; ++i) {
        if (s[i] == t[i])
            continue;
        else {
            ops.push_back(i + 1);
            ops.push_back(1);
            ops.push_back(i + 1);
        }
    }

    cout << ops.size();
    for (int i : ops)
        cout << " " << i;
    cout << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--)
        solve();
}


