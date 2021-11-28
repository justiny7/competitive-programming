#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    string s, t;
    cin >> n >> s >> t;

    map<char, int> s_mp, t_mp;
    for (char c : s)
        ++s_mp[c];
    for (char c: t)
        ++t_mp[c];

    if (s_mp != t_mp) {
        cout << "NO\n";
        return;
    }

    for (char c = 'a'; c <= 'z'; ++c) {
        if (s_mp[c] > 1) {
            cout << "YES\n";
            return;
        }
    }

    int s_inv = 0, t_inv = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            s_inv += s[j] < s[i];
            t_inv += t[j] < t[i];
        }
    }

    if ((s_inv & 1) == (t_inv & 1))
        cout << "YES\n";
    else
        cout << "NO\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--)
        solve();
}

