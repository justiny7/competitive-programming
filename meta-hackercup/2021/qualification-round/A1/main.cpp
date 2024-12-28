#include <bits/stdc++.h>
using namespace std;

bool is_vowel(char c) {
    return (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');
}

void solve() {
    string s;
    cin >> s;

    int n = s.size();

    int ans = INT_MAX;
    for (char c = 'A'; c <= 'Z'; ++c) {
        int here = 0;
        for (int i = 0; i < n; ++i) {
            if (is_vowel(s[i]) ^ is_vowel(c))
                ++here;
            else if (s[i] != c)
                here += 2;
        }

        ans = min(ans, here);
    }

    cout << ans << '\n';
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int t;
    cin >> t;
    for (int tc = 1; tc <= t; ++tc) {
        cout << "Case #" << tc << ": ";
        solve();
    }
}

