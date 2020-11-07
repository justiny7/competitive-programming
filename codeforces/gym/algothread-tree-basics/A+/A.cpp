#include <bits/stdc++.h>
#define pb push_back
using namespace std;

const int mxN=3e5+1;
int n, ans=-1, v_ans;
vector<int> adj[mxN];

void dfs(int v, int p=0, int d=0) {
    if (d>ans)
        ans=d, v_ans=v;
    for (int u:adj[v])
        if (u^p)
            dfs(u, v, d+1);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for (int i=1; i<n; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    dfs(1), ans=-1, dfs(v_ans);
    cout << ans*3 << '\n';
}

