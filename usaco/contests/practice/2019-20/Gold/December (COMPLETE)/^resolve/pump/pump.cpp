//Got it third try after pushing the wrong thing in the pq and changing ans from double to int xd
#include <bits/stdc++.h>
#define pb push_back
using namespace std;
using db=double;

struct edge {
    int v, cst, flo;
};
struct node {
    int v, cst, flo;
    bool operator<(const node &o) const {
        return (cst>o.cst);
    }
};
const int mxN=1e3+1, INF=0x3f3f3f3f;
int n, m, dp[mxN][mxN];
vector<edge> adj[mxN];
priority_queue<node> pq;

int main() {
    memset(dp, 0x3f, sizeof(dp));
    ifstream cin("pump.in");
    ofstream cout("pump.out");
    cin >> n >> m;
    while (m--) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        adj[a].pb(edge{b, c, d});
        adj[b].pb(edge{a, c, d});
    }
    dp[1][(int)1e3]=0;
    pq.push(node{1, 0, (int)1e3});
    while (pq.size()) {
        node here=pq.top(); pq.pop();
        if (dp[here.v][here.flo]^here.cst)
            continue;
        for (edge u:adj[here.v]) {
            int ncst=here.cst+u.cst, nflo=min(here.flo, u.flo);
            if (dp[u.v][nflo]>ncst)
                dp[u.v][nflo]=ncst, pq.push(node{u.v, ncst, nflo});
        }
    }
    int ans=0;
    for (int i=1; i<mxN; ++i)
        ans=max(ans, (int)(((db)i/(db)dp[n][i])*1e6));
    cout << ans << '\n';
}

