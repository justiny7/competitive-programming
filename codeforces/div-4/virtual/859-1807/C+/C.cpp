#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    string s;
    cin >> n >> s;

    map<char, vector<int>> mp;
    for (int i = 0; i < n; ++i)
        mp[s[i]].push_back(i);

    for (char c = 'a'; c <= 'z'; ++c) {
        for (int i = 1; i < mp[c].size(); ++i) {
            if (mp[c][i] % 2 != mp[c][i - 1] % 2) {
                cout << "NO\n";
                return;
            }
        }
    }

    cout << "YES\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--)
        solve();
}

