#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    set<int> s;
    for (int &i : a) {
        cin >> i;
        s.insert(i);
    }
    if (k == 0) {
        cout << n << '\n';
        return;
    }
    int mex = 0, mx = *s.rbegin();
    for (; ; ++mex)
        if (!s.count(mex))
            break;
    int add = (mex + mx + 1) / 2;
    //cout << "add: " << add << '\n';
    if (add == mex)
        cout << n + k << '\n';
    else if (s.count(add))
        cout << n << '\n';
    else
        cout << n + 1 << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--)
        solve();
}
