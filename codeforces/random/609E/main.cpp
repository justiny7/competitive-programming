#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
using namespace std;
using ll=long long;
using pll=pair<ll, ll>;

const int mxN=2e5+1, mxL=20;
const ll INF=0xc0c0c0c0c0c0c0c0;
int n, m, dep[mxN];
pll lift[mxN][mxL];
vector<pll> tadj[mxN], adj[mxN];
struct edge {
    ll v, p, w;
    bool operator<(const edge& o) const {
        return w>o.w;
    }
} edges[mxN];
priority_queue<edge> pq;
bool vis[mxN];

void dfs(int v=1, int d=0) {
    dep[v]=d;
    for (pll u:adj[v]) {
        lift[u.fi][0]=pll(v, u.se);
        for (int i=1; i<mxL; ++i)
            if (lift[u.fi][i-1].fi^INF) {
                lift[u.fi][i]=lift[lift[u.fi][i-1].fi][i-1];
                lift[u.fi][i].se=max(lift[u.fi][i].se, lift[u.fi][i-1].se);
            }
        dfs(u.fi, d+1);
    }
}
ll lca(int a, int b) {
    if (dep[a]<dep[b])
        swap(a, b);
    ll ans=INF;
    for (int i=mxL-1; ~i; --i)
        if (dep[a]>=dep[b]+(1<<i)) {
            pll p=lift[a][i];
            a=p.fi, ans=max(ans, p.se);
        }
    if (a==b)
        return ans;
    for (int i=mxL-1; ~i; --i)
        if (lift[a][i].fi^INF && lift[b][i].fi^INF && lift[a][i].fi^lift[b][i].fi) {
            pll p=lift[a][i], p2=lift[b][i];
            a=p.fi, b=p2.fi, ans=max({ans, p.se, p2.se});
        }
    return max({ans, lift[a][0].se, lift[b][0].se});
}

int main() {
    memset(lift, 0xc0, sizeof(lift));
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    for (int i=0; i<m; ++i) {
        ll a, b, c;
        cin >> a >> b >> c;
        tadj[a].pb(pll(b, c));
        tadj[b].pb(pll(a, c));
        edges[i]=edge{a, b, c};
    }
    pq.push(edge{1, 0, 0});
    ll tot=0;
    while (!pq.empty()) {
        edge e=pq.top(); pq.pop();
        if (vis[e.v])
            continue;
        tot+=e.w;
        if (e.p)
            adj[e.p].pb(pll(e.v, e.w));
        vis[e.v]=1;
        for (pll u:tadj[e.v])
            pq.push(edge{u.fi, e.v, u.se});
    }
    dfs();
    for (int i=0; i<m; ++i)
        cout << tot+edges[i].w-lca(edges[i].v, edges[i].p) << '\n';
}

