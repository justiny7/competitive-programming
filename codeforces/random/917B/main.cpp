#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
using namespace std;
using pic=pair<int, char>;

const int mxN=101;
int n, m, dp[mxN][mxN][256][2];
vector<pic> adj[mxN];

int solve(int v1, int v2, char c, bool turn) {
    if (~dp[v1][v2][c][turn])
        return dp[v1][v2][c][turn];
    int cur=0;
    if (turn) {
        for (pic u:adj[v1])
            if (u.se>=c && solve(u.fi, v2, u.se, !turn))
                cur=1;
    }
    else {
        cur=1;
        for (pic u:adj[v2])
            if (u.se>=c && !solve(v1, u.fi, u.se, !turn))
                cur=0;
    }
    return dp[v1][v2][c][turn]=cur;
}

int main() {
    memset(dp, -1, sizeof(dp));
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    while (m--) {
        int a, b; char c;
        cin >> a >> b >> c;
        adj[a].pb(pic(b, c));
    }
    for (int i=1; i<=n; ++i) {
        for (int j=1; j<=n; ++j)
            cout << (solve(i, j, 'a', 1)?'A':'B');
        cout << '\n';
    }
}

