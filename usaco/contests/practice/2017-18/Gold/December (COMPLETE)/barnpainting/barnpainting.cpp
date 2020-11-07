//Got it second try with a small hint
#include <bits/stdc++.h>
#define pb push_back
using namespace std;
using ll=long long;

ifstream fin("barnpainting.in");
ofstream fout("barnpainting.out");

const int mxN=1e5+1;
const ll M=1e9+7;
int n, k, o[mxN];
ll dp[mxN][3], ans;
vector<int> adj[mxN];

ll solve(int v, int c, int p) {
    if (o[v]>=0 && c!=o[v])
        return 0;
    if (dp[v][c]>=0)
        return dp[v][c];
    dp[v][c]=1;
    for (int u:adj[v])
        if (u!=p) {
            ll cur=0;
            for (int col=0; col<3; ++col)
                if (col!=c)
                    cur=(cur+solve(u, col, v))%M;
            dp[v][c]=(dp[v][c]*cur)%M;
        }
    return dp[v][c];
}

int main() {
    memset(dp, -1, sizeof(dp));
    memset(o, -1, sizeof(o));
    fin >> n >> k;
    for (int i=1; i<n; ++i) {
        int a, b;
        fin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    for (int i=0; i<k; ++i) {
        int v, c;
        fin >> v >> c, --c;
        o[v]=c;
    }
    for (int i=0; i<3; ++i)
        ans=(ans+solve(1, i, -1))%M;
    fout << ans << '\n';
}
