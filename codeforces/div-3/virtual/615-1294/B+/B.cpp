#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<array<int, 2>> v(n);
    for (auto &[x, y] : v)
        cin >> x >> y;

    sort(v.begin(), v.end());

    int cx = 0, cy = 0;
    string res;
    for (auto [nx, ny] : v) {
        if (nx < cx || ny < cy) {
            cout << "NO\n";
            return;
        }

        res += string(nx - cx, 'R');
        res += string(ny - cy, 'U');

        cx = nx, cy = ny;
    }
    
    cout << "YES\n" << res << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--)
        solve();
}

