#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
using ll=long long;
using pll=pair<ll, ll>;
//Got it third try because of index out of bounds+overflow T-T
//At least I got the dp correct
ifstream fin("checklist.in");
ofstream fout("checklist.out");

const int mxN=1e3+2;
ll H, G, dp[mxN][mxN][2];
pll h[mxN], g[mxN];

inline ll dist(pll a, pll b) {
    return (a.fi-b.fi)*(a.fi-b.fi)+(a.se-b.se)*(a.se-b.se);
}

int main() {
    memset(dp, 0x3f, sizeof(dp));
    fin >> H >> G;
    for (int i=1; i<=H; ++i)
        fin >> h[i].fi >> h[i].se;
    for (int i=1; i<=G; ++i)
        fin >> g[i].fi >> g[i].se;
    dp[1][0][0]=0;
    for (int i=1; i<=H; ++i)
        for (int j=0; j<=G; ++j) {
            dp[i+1][j][0]=min(dp[i+1][j][0], dp[i][j][0]+dist(h[i], h[i+1]));
            if (j)
                dp[i+1][j][0]=min(dp[i+1][j][0], dp[i][j][1]+dist(g[j], h[i+1]));
            dp[i][j+1][1]=min(dp[i][j+1][1], dp[i][j][0]+dist(h[i], g[j+1]));
            if (j)
                dp[i][j+1][1]=min(dp[i][j+1][1], dp[i][j][1]+dist(g[j], g[j+1]));
        }
    fout << dp[H][G][0] << '\n';
}

