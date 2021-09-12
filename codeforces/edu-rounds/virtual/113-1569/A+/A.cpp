#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    string s;
    cin >> n >> s;

    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            int c = 0;
            for (int k = i; k <= j; ++k)
                c += s[k] == 'a';

            if (c * 2 == j - i + 1) {
                cout << i + 1 << " " << j + 1 << '\n';
                return;
            }
        }
    }

    cout << "-1 -1\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--)
        solve();
}

