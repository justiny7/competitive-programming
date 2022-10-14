#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    set<int> s;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        s.insert(x);
    }

    if (s.size() == n)
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

