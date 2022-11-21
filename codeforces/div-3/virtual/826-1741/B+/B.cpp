#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    if (n == 3) {
        cout << "-1\n";
        return;
    }
    if (n == 5) {
        cout << "5 4 1 2 3\n";
        return;
    }

    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        a[i] = n - i;

    for (int i = 0; i < n; ++i) {
        if (a[i] == i + 1) {
            assert(i);
            swap(a[i], a[i - 1]);
        }
    }

    for (int i : a)
        cout << i << " ";
    cout << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--)
        solve();
}

