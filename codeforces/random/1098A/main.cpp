#include <bits/stdc++.h>
using namespace std;
using ll=long long;

const int mxN=1e5+1;
int n, par[mxN];
ll s[mxN], ans[mxN];
vector<int> adj[mxN];

void dfs(int v=1) {
    ll mn=LLONG_MAX;
    for (int u:adj[v])
        mn=min(mn, s[u]);
    if (s[v]<0)
        s[v]=(mn^LLONG_MAX?mn:s[par[v]]);
    if (s[par[v]]>s[v]) {
        cout << "-1\n";
        exit(0);
    }
    ans[v]=s[v]-s[par[v]];
    for (int u:adj[v])
        dfs(u);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for (int i=2; i<=n; ++i) {
        cin >> par[i];
        adj[par[i]].push_back(i);
    }
    for (int i=1; i<=n; ++i)
        cin >> s[i];
    ans[1]=s[1];
    dfs();
    ll a=0;
    for (int i=1; i<=n; ++i)
        a+=ans[i];
    cout << a << '\n';
}

