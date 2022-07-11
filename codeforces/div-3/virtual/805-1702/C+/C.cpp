#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (int &i : a)
        cin >> i;

    map<int, int> fst, lst;
    for (int i = 0; i < n; ++i) {
        if (!fst.count(a[i]))
            fst[a[i]] = i;
        lst[a[i]] = i;
    }

    while (k--) {
        int a, b;
        cin >> a >> b;

        if (!fst.count(a) || !fst.count(b))
            cout << "NO\n";
        else {
            if (fst[a] > lst[b])
                cout << "NO\n";
            else
                cout << "YES\n";
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--)
        solve();
}

