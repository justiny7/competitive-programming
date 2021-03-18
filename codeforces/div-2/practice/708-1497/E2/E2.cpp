#include <bits/stdc++.h>
using namespace std;

const int mxN=2e5+1, mxK=21, mxV=1e7+1, INF=1e9;
int n, k, a[mxN], spf[mxV], dp[mxN][mxK], nxt[mxN][mxK];

void sieve() {
    for (int i=1; i<mxV; ++i) {
        if (i&1)
            spf[i]=i;
        else
            spf[i]=2;
    }
    for (int i=3; i*i<mxV; i+=2)
        if (spf[i]==i)
            for (int j=i*i; j<mxV; j+=i)
                spf[j]=i;
}
int conv(int x) {
    int ret=1;
    while (x>1) {
        int c=0, d=spf[x];
        while (x%d==0) {
            ++c;
            x/=d;
        }
        if (c&1)
            ret*=d;
    }
    return ret;
}

void solve() {
    cin >> n >> k;
    for (int i=0; i<=n; ++i)
        for (int j=0; j<=k; ++j)
            dp[i][j]=INF;
    dp[0][0]=0;
    map<int, int> lst;
    set<int> bounds;
    for (int i=0; i<n; ++i)
        cin >> a[i];
    for (int i=n-1; ~i; --i) {
        int x=conv(a[i]);
        if (lst.count(x))
            bounds.insert(lst[x]);
        lst[x]=i;
        auto it=bounds.begin();
        for (int j=0; j<=k; ++j) {
            if (it==bounds.end())
                nxt[i][j]=n;
            else
                nxt[i][j]=*it++;
        }
    }
    for (int i=0; i<n; ++i)
        for (int j=0; j<=k; ++j)
            for (int l=0; l<=k; ++l)
                if (j+l<=k)
                    dp[nxt[i][l]][j+l]=min(dp[nxt[i][l]][j+l], dp[i][j]+1);
    cout << *min_element(dp[n], dp[n]+k+1) << '\n';
}

int main() {
    sieve();
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--)
        solve();
}

