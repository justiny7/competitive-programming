#include <bits/stdc++.h>
using namespace std;
using ll=long long;

const int mxN=5e3+1;
int n, m;
ll dp[mxN];
vector<int> cows, costs;

int main() {
    memset(dp, 0x3f, sizeof(dp));
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    cows.resize(n+1), costs.resize(m+1);
    for (int i=1; i<=n; ++i)
        cin >> cows[i];
    sort(cows.begin(), cows.end());
    for (int i=1; i<=m; ++i)
        cin >> costs[i];
    for (int i=m-1; i; --i)
        costs[i]=min(costs[i], costs[i+1]);
    dp[0]=0;
    for (int i=1; i<=n; ++i)
        for (int j=0; j<i; ++j)
            dp[i]=min(dp[i], dp[j]+costs[cows[i]-cows[j+1]+1]);
    cout << dp[n] << '\n';
}

