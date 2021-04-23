#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, ans = 0, h = 0;
    cin >> n;
    while (n--) {
        int x; cin >> x;
        if (x < h)
            ans += h - x, h = x;
        ans += 2 + x - h;
        h = x;
    }
    cout << ans - 1 << '\n';
}
