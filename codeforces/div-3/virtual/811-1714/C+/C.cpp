#include <bits/stdc++.h>
using namespace std;

void solve() {
    int s;
    cin >> s;

    if (s < 10)
        cout << s << '\n';
    else {
        string res;
        for (int i = 9; i; --i) {
            if (s >= i) {
                res += char(i + '0');
                s -= i;
            }
        }

        reverse(res.begin(), res.end());
        cout << res << '\n';
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--)
        solve();
}

