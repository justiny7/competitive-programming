#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
using namespace std;
using pii=pair<int, int>;

const int mxN=1e6+1;
int n, m, ans1, ans2, to[mxN], scc[mxN], cnt;
vector<int> topo, from[mxN];
vector<vector<int>> b;
bool vis[mxN];

void dfs(int v) {
    vis[v]=1;
    if (!vis[to[v]])
        dfs(to[v]);
    topo.pb(v);
}
void dfs2(int v) {
    scc[v]=cnt;
    for (int u:from[v])
        if (scc[u]<0)
            dfs2(u);
}

void solve() {
    ans1=ans2=cnt=0;
    cin >> n >> m;
    b=vector<vector<int>>(n, vector<int>(m));
    for (int i=0; i<n*m; ++i)
        from[i].clear(), vis[i]=0, scc[i]=-1;
    topo.clear();
    for (int i=0; i<n; ++i) {
        string s; cin >> s;
        for (int j=0; j<m; ++j)
            b[i][j]=(s[j]=='0');
    }
    for (int i=0; i<n; ++i) {
        string s; cin >> s;
        for (int j=0; j<m; ++j) {
            int v=i*m+j, u;
            if (s[j]=='U')
                u=(i-1)*m+j;
            else if (s[j]=='D')
                u=(i+1)*m+j;
            else if (s[j]=='L')
                u=i*m+j-1;
            else
                u=i*m+j+1;
            to[v]=u, from[u].pb(v);
        }
    }
    for (int i=0; i<n*m; ++i)
        if (!vis[i])
            dfs(i);
    for (int i=n*m-1; ~i; --i) {
        int v=topo[i];
        if (scc[v]<0)
            dfs2(v), ++cnt;
    }
    vector<int> sizes(cnt), st(cnt, -1);
    for (int i=0; i<n*m; ++i) {
        ++sizes[scc[i]];
        if (st[scc[i]]<0)
            st[scc[i]]=i;
    }
    for (int i=0; i<cnt; ++i)
        if (sizes[i]>1)
            ans1+=sizes[i];
    cout << ans1 << " ";
    for (int i=0; i<n*m; ++i)
        vis[i]=0;
    for (int i=0; i<cnt; ++i) {
        if (sizes[i]<2)
            continue;
        vector<int> have(sizes[i]);
        queue<pii> q;
        q.push(pii(st[i], 0));
        while (q.size()) {
            int v, d;
            tie(v, d)=q.front(); q.pop();
            if (vis[v])
                continue;
            vis[v]=1, have[d%sizes[i]]|=b[v/m][v%m];
            for (int u:from[v])
                if (!vis[u])
                    q.push(pii(u, d+1));
        }
        for (int j=0; j<sizes[i]; ++j)
            if (have[j])
                ++ans2;
    }
    cout << ans2 << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--)
        solve();
}

