#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s, t;
    cin >> s >> t;

    if (t == "a")
        cout << "1\n";
    else {
        int f = 0;
        for (char c : t)
            f |= (c == 'a');

        if (f)
            cout << "-1\n";
        else {
            long long res = 1;
            for (char c : s)
                if (c == 'a')
                    res *= 2LL;

            cout << res << '\n';
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--)
        solve();
}

