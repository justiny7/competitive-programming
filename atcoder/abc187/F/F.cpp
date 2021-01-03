#include <bits/stdc++.h>
using namespace std;

const int mxN=18;
int n, m, dp[1<<mxN];
bool adj[mxN][mxN];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    while (m--) {
        int a, b;
        cin >> a >> b, --a, --b;
        adj[a][b]=adj[b][a]=1;
    }
    for (int i=0; i<(1<<n); ++i) {
        vector<int> here;
        for (int j=0; j<n; ++j)
            if (i&(1<<j))
                here.push_back(j);
        bool f=1;
        for (int j=0; j<here.size(); ++j)
            for (int k=j+1; k<here.size(); ++k)
                f&=adj[here[j]][here[k]];
        dp[i]=(f?1:1e9);
    }
    for (int i=0; i<(1<<n); ++i)
        for (int j=i; j; j=(j-1)&i)
            dp[i]=min(dp[i], dp[j]+dp[i^j]);
    cout << dp[(1<<n)-1] << '\n';
}

