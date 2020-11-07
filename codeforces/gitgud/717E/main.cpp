#include <bits/stdc++.h>
#define pb push_back
using namespace std;

const int mxN=2e5+1;
int n;
vector<int> adj[mxN], ans;
bool col[mxN];

void dfs(int v=1, int p=0) {
    ans.pb(v);
    if (p)
        col[v]^=1;
    bool f=0;
    for (int u:adj[v])
        if (u^p) {
            f=1, dfs(u, v);
            ans.pb(v);
            col[v]^=1;
        }
    if (p && !col[v]) {
        ans.pb(p);
        ans.pb(v);
        col[v]=1, col[p]^=1;
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    bool tmp=1;
    for (int i=1; i<=n; ++i) {
        int a; cin >> a;
        tmp&=(col[i]=(a>0));
    }
    if (tmp)
        return cout << "1\n", 0;
    for (int i=1; i<n; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    dfs();
    if (!col[1])
        ans.pop_back();
    for (int i=0; i<ans.size(); ++i)
        cout << ans[i] << (i==ans.size()-1?"\n":" ");
}

