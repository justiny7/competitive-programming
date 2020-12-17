#include <bits/stdc++.h>
using namespace std;
using ll=long long;

const int mxN=1e3+1;
vector<int> v={0};
int n;
ll dp[mxN];

ll dfs(int cur) {
    if (~dp[cur])
        return dp[cur];
    ll here=0;
    for (int i=cur+1; i<n && v[i]-v[cur]<=3; ++i)
        here+=dfs(i);
    return dp[cur]=here;
}

int main() {
    memset(dp, -1, sizeof(dp));
    freopen("test.txt", "r", stdin);
    int x, mx=0, c1=0, c3=0;
    while (cin >> x)
        v.push_back(x), mx=max(mx, v.back());
    v.push_back(mx+3);
    n=v.size();
    dp[n-1]=1;
    sort(v.begin(), v.end());
    cout << dfs(0) << '\n';
}

