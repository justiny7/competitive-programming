#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<array<int, 3>> a(n);
    for (int i=0; i<n; ++i)
        cin >> a[i][1] >> a[i][0], a[i][2]=i;
    int c=0, j=0;
    sort(a.begin(), a.end());
    string ans(n, '-');
    for (auto [en, st, ind]:a) {
        if (c<=st && j<=st) {
            if (c>j) {
                c=en;
                ans[ind]='C';
            }
            else {
                j=en;
                ans[ind]='J';
            }
        }
        else if (c<=st) {
            c=en;
            ans[ind]='C';
        }
        else if (j<=st) {
            j=en;
            ans[ind]='J';
        }
        else {
            cout << "IMPOSSIBLE\n";
            return;
        }
    }
    cout << ans << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    for (int tc=1; tc<=t; ++tc) {
        cout << "Case #" << tc << ": ";
        solve();
    }
}

