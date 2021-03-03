#include <bits/stdc++.h>
using namespace std;
using ll=long long;

const int mxN=1e5+1;
int n, par[mxN];
ll c[mxN], ans[mxN];
vector<int> adj[mxN];
map<ll, ll> cnt[mxN], mp[mxN];

int find(int v) {
    return (v==par[v]?v:par[v]=find(par[v]));
}
bool merge(int a, int b) {
    a=find(a), b=find(b);
    if (a==b)
        return 0;
    if (cnt[a].size()>cnt[b].size())
        swap(a, b);
    par[a]=b;
    for (auto p:cnt[a]) {
        ll &here=cnt[b][p.first];
        here+=p.second;
        mp[b][here]+=p.first;
    }
    cnt[a].clear();
    mp[a].clear();
    return 1;
}
void dfs(int v=1, int p=0) {
    for (int u:adj[v]) {
        if (u==p)
            continue;
        dfs(u, v);
        merge(v, u);
    }
    ans[v]=mp[find(v)].rbegin()->second;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for (int i=1; i<=n; ++i)
        cin >> c[i], par[i]=i, cnt[i][c[i]]=1, mp[i][1]=c[i];
    for (int i=1; i<n; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs();
    for (int i=1; i<=n; ++i)
        cout << ans[i] << " \n"[i==n];
}

