//either all rows are alternating or all columns?
#include <bits/stdc++.h>
using namespace std;

const int mxN=1e3+1;
int n, ret1, ret2, a[mxN][mxN];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for (int i=0; i<n; ++i)
        for (int j=0; j<n; ++j)
            cin >> a[i][j];
    for (int i=0; i<n; ++i) {
        int e=0, o=0;
        for (int j=0; j<n; ++j) {
            if (j&1)
                o+=a[i][j];
            else
                e+=a[i][j];
        }
        ret1+=max(o, e);
        e=0, o=0;
        for (int j=0; j<n; ++j) {
            if (j&1)
                o+=a[j][i];
            else
                e+=a[j][i];
        }
        ret2+=max(o, e);
    }
    cout << max(ret1, ret2) << '\n';
}

