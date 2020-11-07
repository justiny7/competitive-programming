#include <bits/stdc++.h>
using namespace std;

const int mxN=1e3+1;
int n, q, pref[mxN][mxN];

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> q;
    for (int i=1; i<=n; ++i)
        for (int j=1; j<=n; ++j) {
            char c; cin >> c;
            pref[i][j]=(c=='*');
            pref[i][j]+=pref[i-1][j]+pref[i][j-1]-pref[i-1][j-1];
        }
    while (q--) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        cout << pref[c][d]+pref[a-1][b-1]-pref[c][b-1]-pref[a-1][d] << '\n';
    }
}
