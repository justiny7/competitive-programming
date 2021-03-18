#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    if (n&1)
        cout << n/2 << " " << n/2 << " 1\n";
    else {
        if (n%4==0)
            cout << n/2 << " " << n/4 << " " << n/4 << '\n';
        else
            cout << n/2-1 << " " << n/2-1 << " 2\n";
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--)
        solve();
}

