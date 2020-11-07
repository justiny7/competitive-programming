//Got it second try because of overflow xd
#include <bits/stdc++.h>
using namespace std;

const int mxN=201;
int n, m, x, q, d[mxN][mxN];

int main() {
    ifstream cin("vacation.in");
    ofstream cout("vacation.out");
    memset(d, 0x3f, sizeof(d));
    cin >> n >> m >> x >> q;
    while (m--) {
        int a, b, c;
        cin >> a >> b >> c;
        d[a][b]=min(d[a][b], c);
    }
    for (int k=1; k<=n; ++k)
        for (int i=1; i<=n; ++i)
            for (int j=1; j<=n; ++j)
                d[i][j]=min(d[i][j], d[i][k]+d[k][j]);
    for (int i=1; i<=n; ++i)
        d[i][i]=0;
    int c=0;
    long long ans=0;
    while (q--) {
        int a, b, mn=INT_MAX;
        cin >> a >> b;
        for (int i=1; i<=x; ++i)
            mn=min(mn, d[a][i]+d[i][b]);
        if (mn<0x3f3f3f3f)
            ans+=mn, ++c;
    }
    cout << c << '\n' << ans << '\n';
}

