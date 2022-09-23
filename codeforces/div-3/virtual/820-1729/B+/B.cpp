#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    string s;
    cin >> n >> s;

    string res;
    for (int i = n - 1; ~i; --i) {
        int c;
        if (s[i] == '0') {
            c = (s[i - 2] - '0') * 10 + (s[i - 1] - '0') - 1;
            i -= 2;
        } else {
            c = (s[i] - '0') - 1;
        }

        res += char('a' + c);
    }

    reverse(res.begin(), res.end());
    cout << res << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--)
        solve();
}

