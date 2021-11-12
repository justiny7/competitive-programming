#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    string s;
    cin >> s;

    int res = INT_MAX;
    for (char c = 'a'; c <= 'z'; ++c) {
        int here = 0;

        int l = 0, r = n - 1;
        while (l < r) {
            while (l < n && s[l] != s[r] && s[l] == c)
                ++l, ++here;
            while (r > l && s[l] != s[r] && s[r] == c)
                --r, ++here;

            if (s[l] != s[r]) {
                here = INT_MAX;
                break;
            }

            ++l, --r;
        }

        res = min(res, here);
    }

    cout << (res == INT_MAX ? -1 : res) << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--)
        solve();
}

