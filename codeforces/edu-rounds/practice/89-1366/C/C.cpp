#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, m, b[31][31], c[61][2], ans=0;
        memset(c, 0, sizeof(c));
        cin >> n >> m;
        for (int i=0; i<n; ++i)
            for (int j=0; j<m; ++j)
                cin >> b[i][j];
        for (int i=0; i<n; ++i)
            for (int j=0; j<m; ++j)
                c[i+j][b[i][j]]++;
        int q=m+n-2;
        for (int i=0; i<=q; ++i) {
            int j=q-i;
            if (i<=j)
                continue;
            ans+=min(c[i][0]+c[j][0], c[i][1]+c[j][1]);
        }
        cout << ans << '\n';
    }
}
