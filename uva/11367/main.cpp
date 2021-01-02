#include <bits/stdc++.h>
#define ar3 array<int, 3>
using namespace std;
using pii=pair<int, int>;

const int mxN=1001, mxC=101, INF=0x3f3f3f3f;
int n, m, q, p[mxN], dp[mxN][mxC];
vector<pii> adj[mxN];
priority_queue<ar3, vector<ar3>, greater<ar3>> pq;

int solve(int st, int en, int cap) {
    for (int i=0; i<n; ++i)
        for (int j=0; j<=cap; ++j)
            dp[i][j]=INF;
    pq.push({0, 0, st});
    dp[st][0]=0;
    while (pq.size()) {
        ar3 here=pq.top(); pq.pop();
        int c=here[0], g=here[1], v=here[2];
        if (c^dp[v][g])
            continue;
        {
            int gas=g+1, nxt=c+p[v];
            if (gas<=cap && nxt<dp[v][gas]) {
                dp[v][gas]=nxt;
                pq.push({nxt, gas, v});
            }
        }
        for (pii pi:adj[v]) {
            int u=pi.first, gas=g-pi.second;
            if (gas>=0 && c<dp[u][gas]) {
                dp[u][gas]=c;
                pq.push({c, gas, u});
            }
        }
    }
    int ret=INF;
    for (int i=0; i<=cap; ++i)
        ret=min(ret, dp[en][i]);
    return ret;
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i=0; i<n; ++i)
        scanf("%d", &p[i]);
    while (m--) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        adj[a].emplace_back(b, c);
        adj[b].emplace_back(a, c);
    }
    scanf("%d", &q);
    while (q--) {
        int st, en, cap, ans;
        scanf("%d %d %d", &cap, &st, &en);
        ans=solve(st, en, cap);
        if (ans^INF)
            printf("%d\n", ans);
        else
            printf("impossible\n");
    }
}

