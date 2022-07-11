#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s;
    int p;
    cin >> s >> p;

    int n = s.size();

    vector<int> pos[26];
    int cur = 0;
    for (int i = 0; i < n; ++i) {
        pos[s[i] - 'a'].push_back(i);
        cur += (s[i] - 'a') + 1;
    }

    for (int i = 25; ~i && cur > p; --i) {
        while (pos[i].size() && cur > p) {
            cur -= i + 1;
            s[pos[i].back()] = '.';
            pos[i].pop_back();
        }
    }

    string res;
    for (char c : s)
        if (c != '.')
            res += c;

    cout << res << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--)
        solve();
}


