#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
using namespace std;
using ll=long long;
using pii=pair<int, int>;

const int mxN=1e5+1;
int n, cnt[64], ans=INT_MAX;
vector<ll> a;
vector<int> adj[mxN];
vector<pii> edges;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for (int i=0; i<n; ++i) {
        ll c; cin >> c;
        if (!c)
            continue;
        a.pb(c);
        for (int j=0; j<64; ++j)
            if (c&(1LL<<j))
                ++cnt[j];
    }
    bool f=0;
    for (int i=0; i<64; ++i) {
        f|=(cnt[i]>1);
        if (cnt[i]>=3)
            return cout << "3\n", 0;
    }
    if (!f)
        return cout << "-1\n", 0;
    //n is probably pretty small now
    n=a.size();
    for (int i=0; i<n; ++i)
        for (int j=i+1; j<n; ++j)
            if (a[i]&a[j]) {
                adj[i].pb(j);
                adj[j].pb(i);
                edges.pb(pii(i, j));
            }
    for (pii p:edges) {
        queue<int> q;
        vector<int> dist(n, -1);
        q.push(p.fi);
        dist[p.fi]=0;
        while (q.size()) {
            int v=q.front(); q.pop();
            for (int u:adj[v]) {
                pii c=minmax(u, v);
                if (c!=p && dist[u]<0) {
                    dist[u]=dist[v]+1;
                    q.push(u);
                }
            }
        }
        if (~dist[p.se])
            ans=min(ans, dist[p.se]+1);
    }
    cout << (ans==INT_MAX?-1:ans) << '\n';
}

