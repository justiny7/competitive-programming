#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
using namespace std;
using pii=pair<int, int>;

const int mxN=3e5+1, INF=0x3f3f3f3f;
int n, m, q, d[mxN];
pii lift[mxN][20];
vector<pii> adj[mxN];

void dfs(int v=1, int p=1, int dep=0) {
    d[v]=dep;
    for (pii u:adj[v])
        if (u.fi^p) {
            lift[u.fi][0]=pii(v, u.se);
            for (int i=1; i<20; ++i)
                if (lift[u.fi][i-1].fi^INF) {
                    lift[u.fi][i]=lift[lift[u.fi][i-1].fi][i-1];
                    lift[u.fi][i].se=min(lift[u.fi][i].se, lift[u.fi][i-1].se);
                }
            dfs(u.fi, v, dep+1);
        }
}

int lca(int a, int b) {
    if (d[a]<d[b])
        swap(a, b);
    int ans=INF;
    for (int i=19; ~i; --i)
        if (d[a]>=d[b]+(1<<i)) {
            pii p=lift[a][i];
            a=p.fi, ans=min(ans, p.se);
        }
    if (a==b)
        return ans;
    for (int i=19; ~i; --i)
        if (lift[a][i].fi^INF && lift[a][i].fi^lift[b][i].fi) {
            pii p=lift[a][i], p2=lift[b][i];
            a=p.fi, b=p2.fi, ans=min({ans, p.se, p2.se});
        }
    return min({ans, lift[a][0].se, lift[b][0].se});
}

int main() {
    memset(lift, 0x3f, sizeof(lift));
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    while (m--) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].pb(pii(b, c));
        adj[b].pb(pii(a, c));
    }
    dfs();
    cin >> q;
    while (q--) {
        int a, b;
        cin >> a >> b;
        cout << lca(a, b) << '\n';
    }
}

