#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int &i : a)
        cin >> i;

    auto get = [](int a, int b, bool f) {
        int tot = abs(a * b);

        if (!f)
            return tot / a;
        else
            return -tot / b;
    };

    if (n & 1) {
        int s;
        if (a[0] + a[1] != 0)
            cout << -a[2] << " " << -a[2] << " " << a[0] + a[1] << " ";
        else if (a[0] + a[2] != 0)
            cout << -a[1] << " " << a[0] + a[2] << " " << -a[1] << " ";
        else
            cout << a[1] + a[2] << " " << -a[0] << " " << -a[0] << " ";
    }

    for (int i = (n & 1) ? 3 : 0; i < n; i += 2)
        cout << get(a[i], a[i + 1], 0) << " " << get(a[i], a[i + 1], 1) << " ";
    cout << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--)
        solve();
}

