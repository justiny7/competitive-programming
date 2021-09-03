#include <bits/stdc++.h>
using namespace std;

const string C = "RB";

void solve() {
    int n;
    string s;
    cin >> n >> s;

    int l = 0, r = 0;
    while (l < n) {
        while (l < n && s[l] != '?')
            ++l;

        r = l;
        while (r < n && s[r] == '?')
            ++r;

        int len = r - l;

        if (len == n) {
            for (int i = 0; i < n; ++i)
                s[i] = (i & 1) ? 'B' : 'R';
            break;
        } else if (l > 0) {
            int bef = (s[l - 1] == 'B');
            for (int i = l; i < r; ++i)
                s[i] = ((i & 1) == (l & 1)) ? C[bef ^ 1] : C[bef];
        } else {
            if ((len & 1) == (s[r] == 'B')) {
                for (int i = 0; i < r; ++i)
                    s[i] = (i & 1) ? 'B' : 'R';
            } else {
                for (int i = 0; i < r; ++i)
                    s[i] = (i & 1) ? 'R' : 'B';
            }
        }

        l = r;
    }

    cout << s << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--)
        solve();
}

