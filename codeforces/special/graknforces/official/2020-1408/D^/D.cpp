#include <bits/stdc++.h>
using namespace std;

const int mxN=2e3+1, mxV=1e6+1;
int n, m, x[mxV], a[mxN], b[mxN], c[mxN], d[mxN];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    for (int i=0; i<n; ++i)
        cin >> a[i] >> b[i];
    for (int i=0; i<m; ++i)
        cin >> c[i] >> d[i];
    for (int i=0; i<n; ++i)
        for (int j=0; j<m; ++j)
            if (c[j]-a[i]>=0)
                x[c[j]-a[i]]=max(x[c[j]-a[i]], d[j]-b[i]+1);
    for (int i=mxV-2; ~i; --i)
        x[i]=max(x[i], x[i+1]);
    int ans=INT_MAX;
    for (int i=0; i<mxV; ++i)
        ans=min(ans, i+x[i]);
    cout << ans << '\n';
}

