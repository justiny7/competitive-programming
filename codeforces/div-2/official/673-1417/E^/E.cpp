#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n, xans; ll ans;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    vector<int> a(n);
    for (int &i : a)
        cin >> i;
    vector<vector<int>> cur = {a};
    for (int b = 30; ~b; --b) {
        vector<vector<int>> nxt;
        ll xcnt = 0, ycnt = 0;
        for (auto v : cur) {
            vector<int> x, y;
            for (int i : v) {
                if (i & (1 << b)) {
                    y.push_back(i);
                    ycnt += x.size();
                }
                else {
                    x.push_back(i);
                    xcnt += y.size();
                }
            }
            if (x.size())
                nxt.push_back(x);
            if (y.size())
                nxt.push_back(y);
        }
        ans += min(xcnt, ycnt);
        if (ycnt < xcnt)
            xans |= (1 << b);
        cur = nxt;
    }
    cout << ans << " " << xans << '\n';
}
