#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll inv(vector<int> &a) {
    ll res = 0, cur = 0;
    for (int i = a.size() - 1; ~i; --i) {
        if (a[i] == 0)
            ++cur;
        else
            res += cur;
    }
    return res;
}

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int &i : a)
        cin >> i;

    ll res = inv(a);

    vector<int> b(a);
    for (int i = 0; i < n; ++i) {
        if (a[i] == 0) {
            b[i] = 1;
            res = max(res, inv(b));
            b[i] = 0;
            break;
        }
    }
    for (int i = n - 1; ~i; --i) {
        if (a[i] == 1) {
            b[i] = 0;
            res = max(res, inv(b));
            b[i] = 1;
            break;
        }
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

