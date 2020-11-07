//Yay got it fourth try
#include <bits/stdc++.h>
#define pb push_back
using namespace std;
using ll=long long;

const int mxN=1e3+1;
int n, m, c;
vector<int> adj[mxN];
bool ok[mxN];
ll ans, mon[mxN], dp[mxN][mxN];

int main() {
    ifstream cin("time.in");
    ofstream cout("time.out");
    cin >> n >> m >> c;
    for (int i=1; i<=n; ++i)
        cin >> mon[i];
    while (m--) {
        int a, b;
        cin >> a >> b;
        adj[a].pb(b);
    }
    ok[1]=1;
    set<int> cur={1}, nxt;
    for (int i=1; i<mxN; ++i) {
        for (int v:cur)
            for (int u:adj[v]) {
                dp[i][u]=max(dp[i][u], dp[i-1][v]+mon[u]);
                if (u==1)
                    ans=max(ans, dp[i][u]-ll(c*i*i));
                nxt.insert(u);
            }
        cur=nxt, nxt.clear();
    }
    cout << ans << '\n';
}

