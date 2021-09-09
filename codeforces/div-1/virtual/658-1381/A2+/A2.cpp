#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    string s, t;
    cin >> n >> s >> t;

    s += '1', t += '1';
    ++n;

    vector<int> ops, rev;
    for (int i = 1; i < n; ++i)
        if (s[i - 1] != s[i])
            ops.push_back(i);

    for (int i = 1; i < n; ++i)
        if (t[i - 1] != t[i])
            rev.push_back(i);

    while (rev.size()) {
        ops.push_back(rev.back());
        rev.pop_back();
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

