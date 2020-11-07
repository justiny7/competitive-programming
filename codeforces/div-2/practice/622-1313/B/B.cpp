#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n, x, y;
        cin >> n >> x >> y;
        cout << max(min(x+y-n+1, n), 1) << " " << min(n, x+y-1) << '\n';
    }
}


