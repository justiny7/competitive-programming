#include <bits/stdc++.h>
using namespace std;
using ll=long long;

const int mxN=3e5+1;
int n, cnt;
vector<int> adj[mxN];
ll targ=LLONG_MIN, c[mxN], dp[mxN][2];

void dfs(int v=1, int p=0) {
    dp[v][1]=c[v];
    for (int u:adj[v])
        if (u^p) {
            dfs(u, v);
            dp[v][0]=max(dp[v][0], dp[u][0]);
            dp[v][1]+=max(dp[u][1], 0LL);
        }
    dp[v][0]=max(dp[v][0], dp[v][1]);
    targ=max({targ, dp[v][0], dp[v][1]});
}
ll dfs2(int v=1, int p=0) {
    ll ret=c[v];
    for (int u:adj[v])
        if (u^p) {
            ll nxt=dfs2(u, v);
            ret+=max(nxt, 0LL);
        }
    return (ret==targ?++cnt, 0:ret);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for (int i=1; i<=n; ++i)
        cin >> c[i], targ=max(targ, c[i]);
    for (int i=1; i<n; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    if (targ>0)
        dfs();
    dfs2();
    cout << (ll)cnt*targ << " " << cnt << '\n';
}

