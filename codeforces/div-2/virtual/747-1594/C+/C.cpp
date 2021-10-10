#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    char c;
    string s;
    cin >> n >> c >> s;

    if (count(s.begin(), s.end(), c) == n)
        cout << "0\n";
    else {
        for (int i = 2; i <= n; ++i) {
            bool f = 1;
            for (int j = i - 1; j < n; j += i)
                f &= s[j] == c;

            if (f) {
                cout << "1\n";
                cout << i << '\n';
                return;
            }
        }

        cout << "2\n";
        cout << n << " " << n - 1 << '\n';
    }

}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--)
        solve();
}

