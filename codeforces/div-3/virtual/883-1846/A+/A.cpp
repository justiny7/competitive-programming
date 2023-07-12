#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    int res = n;
    while (n--) {
        int a, b;
        cin >> a >> b;
        if (a - b <= 0)
            --res;
    }
    
    cout << res << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--)
        solve();
}

