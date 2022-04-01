#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int &i : a)
        cin >> i;

    a.push_back(0);
    sort(a.begin(), a.end());

    if (a.back() - a[a.size() - 2] > 1)
        cout << "NO\n";
    else
        cout << "YES\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--)
        solve();
}

