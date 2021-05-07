#include <bits/stdc++.h>
using namespace std;

bool cmp(string a, string b) {
    if (a.size() > b.size())
        return 1;
    if (a.size() < b.size())
        return 0;
    for (int i = 0; i < a.size(); ++i) {
        if (a[i] > b[i])
            return 1;
        if (a[i] < b[i])
            return 0;
    }
    return 0;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int x; cin >> x;
        bool f = 0;
        int ans = 0;
        for (int i = 1; i < 10; ++i) {
            for (char j = '1'; j <= '9'; ++j) {
                if (cmp(string(i, j), to_string(x))) {
                    f = 1;
                    break;
                }
                ++ans;
            }
            if (f)
                break;
        }
        cout << ans << '\n';
    }
}
