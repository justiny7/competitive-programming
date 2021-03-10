#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k=0, r=0, c=0; cin >> n;
    vector<vector<int>> a(n, vector<int>(n));
    vector<set<int>> col(n), row(n);
    for (int i=0; i<n; ++i) {
        for (int j=0; j<n; ++j) {
            cin >> a[i][j];
            if (i==j)
                k+=a[i][j];
            row[i].insert(a[i][j]);
            col[j].insert(a[i][j]);
        }
    }
    for (int i=0; i<n; ++i) {
        if (row[i].size()<n)
            ++r;
        if (col[i].size()<n)
            ++c;
    }
    cout << k << " " << r << " " << c << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    for (int tc=1; tc<=t; ++tc) {
        cout << "Case #" << tc << ": ";
        solve();
    }
}

