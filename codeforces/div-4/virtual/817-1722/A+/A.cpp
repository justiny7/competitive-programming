#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    string s;
    cin >> n >> s;

    if (n != 5) {
        cout << "NO\n";
        return;
    }

    string ss = "Timur";
    sort(ss.begin(), ss.end());
    sort(s.begin(), s.end());

    cout << (s == ss ? "YES" : "NO") << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--)
        solve();
}

