#include <bits/stdc++.h>
using namespace std;

const int mxN=2e5+1;
int n, m, q, a[mxN], dp[mxN][30], p[mxN], p_at[mxN], lst[mxN], beg[mxN];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m >> q;
    for (int i=1; i<=n; ++i)
        cin >> p[i], p_at[p[i]]=i;
    p[0]=p[n];
    for (int i=1; i<=m; ++i)
        cin >> a[i], dp[i][0]=lst[p[p_at[a[i]]-1]], lst[a[i]]=i;
    for (int i=1; i<30; ++i)
        for (int j=1; j<=m; ++j)
            dp[j][i]=dp[dp[j][i-1]][i-1];
    for (int i=1; i<=m; ++i) {
        int k=n-1, cur, v=i;
        while (k)
            cur=log2(k), v=dp[v][cur], k-=exp2(cur);
        beg[i]=max(v, beg[i-1]);
    }
    while (q--) {
        int l, r;
        cin >> l >> r;
        if (beg[r]>=l)
            cout << 1;
        else
            cout << 0;
    }
    cout << '\n';
}

