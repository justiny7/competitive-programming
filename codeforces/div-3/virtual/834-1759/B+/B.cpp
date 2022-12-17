#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, s;
    cin >> n >> s;

    int tot = 0;
    vector<int> a(n);
    for (int &i : a)
        cin >> i, tot += i;

    for (int i = 1; ; ++i) {
        int here = i * (i + 1) / 2;
        if (here > tot + s) {
            cout << "NO\n";
            return;
        } else if (here == tot + s) {
            set<int> cur;
            for (int j = 1; j <= i; ++j)
                cur.insert(j);

            for (int j : a)
                cur.erase(j);

            int k = 0;
            for (int j : cur)
                k += j;

            if (k != s)
                cout << "NO\n";
            else
                cout << "YES\n";
            return;
        }
    }
    
    assert(false);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--)
        solve();
}

