#include <bits/stdc++.h>
#define pb push_back
using namespace std;

const int mxN=5e3+1;
int n, cnt[mxN];
vector<int> adj[mxN];
bitset<mxN> ans;

void dfs(int v=1, int p=0) {
    cnt[v]=1;
    bitset<mxN> cur=1;
    for (int u:adj[v])
        if (u^p) {
            dfs(u, v);
            cnt[v]+=cnt[u];
            cur|=(cur<<cnt[u]);
        }
    cur|=(cur<<(n-cnt[v])), ans|=cur;
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
    dfs();
    int c=0;
    for (int i=1; i<n-1; ++i)
        c+=ans[i];
    cout << c << '\n';
    for (int i=1; i<n-1; ++i)
        if (ans[i])
            cout << i << " " << n-i-1 << '\n';
}


