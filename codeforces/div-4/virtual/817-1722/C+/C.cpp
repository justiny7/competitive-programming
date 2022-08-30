#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    set<string> s[3];

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < n; ++j) {
            string cur;
            cin >> cur;
            s[i].insert(cur);
        }
    }

    for (int i = 0; i < 3; ++i) {
        int res = 0;

        for (string cur : s[i]) {
            int c = 0;
            for (int j = 0; j < 3; ++j) {
                if (i == j)
                    continue;
                c += s[j].count(cur);
            }

            if (c == 0)
                res += 3;
            else if (c == 1)
                ++res;
        }

        cout << res << " \n"[i == 2];
    }

}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--)
        solve();
}

