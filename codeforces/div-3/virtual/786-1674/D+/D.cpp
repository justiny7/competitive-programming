#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int &i : a)
        cin >> i;

    for (int i = n - 1; i > 0; i -= 2)
        if (a[i] < a[i - 1])
            swap(a[i], a[i - 1]);

    cout <<  (is_sorted(a.begin(), a.end()) ? "YES" : "NO") << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--)
        solve();
}

