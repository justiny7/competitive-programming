#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    string s;
    cin >> n >> s;

    for (int i = 0; i < n; ++i) {
        if (s[i] == 'L' || s[i] == 'R')
            cout << s[i];
        else if (s[i] == 'U')
            cout << 'D';
        else
            cout << 'U';
    }
    
    cout << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--)
        solve();
}

