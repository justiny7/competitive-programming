//Looked at solution as well T-T
#include <bits/stdc++.h>
#define pb push_back
using namespace std;

const int mxN=1e5+1;
int n, cnt[mxN], c[mxN];
vector<int> adj[mxN], sub[mxN];

void dfs(int v=1, int p=0) {
    cnt[v]=1;
    for (int u:adj[v])
        if (u^p) {
            dfs(u, v);
            cnt[v]+=cnt[u];
            sub[v].pb(cnt[u]);
        }
    if (v^1)
        sub[v].pb(n-cnt[v]); //get all subtree sizes
}

bool works(int x) {
    if ((n-1)%x)
        return 0;
    memset(c, 0, sizeof(c));
    for (int i=1; i<=n; ++i)  {
        int cur=0;
        for (int j:sub[i]) { //balances out subtree sizes when modded by x
            int m=j%x;
            if (!m)
                continue;
            if (c[x-m])
                --c[x-m], --cur;
            else
                ++c[m], ++cur;
        }
        if (cur)
            return 0;
    }
    return 1;
}

int main() {
    ifstream cin("deleg.in");
    ofstream cout("deleg.out");
    cin >> n;
    for (int i=1; i<n; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    dfs();
    for (int i=1; i<n; ++i)
        cout << (works(i)?1:0);
    cout << '\n';
}

