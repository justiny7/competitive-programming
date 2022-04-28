#include <bits/stdc++.h>
using namespace std;

void solve() {
    int x;
    cin >> x;

    cout << "Division ";
    if (x < 1400)
        cout << "4";
    else if (x < 1600)
        cout << "3";
    else if (x < 1900)
        cout << "2";
    else
        cout << "1";
    cout << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--)
        solve();
}

