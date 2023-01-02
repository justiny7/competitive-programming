#include <bits/stdc++.h>
using namespace std;

map<string, int> mp;

void solve() {
    string s;
    cin >> s;
    cout << mp[s] << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    string s = "aa";

    while (s != "zz") {
        if (s[0] != s[1])
            mp[s] = mp.size() + 1;

        if (s[1] == 'z') {
            s[0]++;
            s[1] = 'a';
        } else {
            s[1]++;
        }
    }

    int t;
    cin >> t;
    while (t--)
        solve();
}

