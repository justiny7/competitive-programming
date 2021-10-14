#include <bits/stdc++.h>
using namespace std;

void solve() {
    long long x;
    cin >> x;

    string s = to_string(x);
    int ans = INT_MAX, sz = s.size();
    for (string targ : {"00", "25", "50", "75"}) {
        int rem = 0, pos = 1;
        for (int i = sz - 1; ~i; --i) {
            if (s[i] == targ[pos]) {
                --pos;
                if (pos < 0)
                    break;
            } else {
                ++rem;
            }
        }

        if (pos < 0)
            ans = min(ans, rem);
    }

    cout << ans << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--)
        solve();
}

