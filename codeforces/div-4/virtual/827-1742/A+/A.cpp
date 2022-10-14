#include <bits/stdc++.h>
using namespace std;

void solve() {
    int a, b, c;
    cin >> a >> b >> c;

    if (a + b == c || a + c == b || c + b == a)
        cout << "YES\n";
    else
        cout << "NO\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    int t;
    cin >> t;
    while (t--)
        solve();
}

