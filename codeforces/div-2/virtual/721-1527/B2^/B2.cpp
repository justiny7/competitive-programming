#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; string s;
    cin >> n >> s;

    int z = count(s.begin(), s.end(), '0');

    int dif = 0, z_pair = 0;
    for (int i = 0; i < n / 2; ++i) {
        dif += (s[i] != s[n - i - 1]);
        z_pair += (s[i] == '0' && s[n - i - 1] == '0');
    }

    bool center = (n & 1) && (s[n / 2] == '0');

    if (dif) {
        if (z_pair == 0 && dif == 1 && center)
            cout << "DRAW\n";
        else
            cout << "ALICE\n";
    }
    else { // Bob matches Alice's move until there's 1 left, then flips
        if (n % 2 == 0 || !center || z <= 2)
            cout << "BOB\n";
        else
            cout << "ALICE\n";
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t; cin >> t;
    while (t--)
        solve();
}
