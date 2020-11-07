#include <bits/stdc++.h>
#define BIG 1e18
using namespace std;
typedef long long ll;

ll n, m, q, dist[501][501];

int main(void) {
    cin >> n >> m >> q;
    for (int i=1; i<=n; ++i)
        for (int j=1; j<=n; ++j)
            dist[i][j]=BIG;
    for (int i=0; i<m; ++i) {
        ll a, b, c;
        cin >> a >> b >> c;
        dist[a][b]=min(dist[a][b], c);
        dist[b][a]=dist[a][b];
    }
    for (int i=1; i<=n; ++i)
        dist[i][i]=0;
    for (int k=1; k<=n; ++k)
        for (int i=1; i<=n; ++i)
            for (int j=1; j<=n; ++j)
                dist[i][j]=min(dist[i][j], dist[i][k]+dist[k][j]);
    for (int i=0; i<q; ++i) {
        int a, b;
        cin >> a >> b;
        if (dist[a][b]!=BIG)
            cout << dist[a][b] << '\n';
        else
            cout << "-1\n";
    }
}
