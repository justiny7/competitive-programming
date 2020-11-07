#include <bits/stdc++.h>
using namespace std;
using ll=long long;

const int mxN=2e5+1;
const ll M=1e9+7;
int n, a[mxN], sz[mxN], cur, vis[mxN];
ll p[mxN], ans=1;

void dfs(int v) {
    vis[v]=1;
    if (!vis[a[v]])
        dfs(a[v]);
    else if (vis[a[v]]^2) {
        while (vis[v]^3)
            ++sz[cur], vis[v]=3, v=a[v];
        ++cur;
    }
    vis[v]=2;
}

int main() {
    p[0]=1;
    for (int i=1; i<mxN; ++i)
        p[i]=(p[i-1]*2)%M;
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for (int i=1; i<=n; ++i)
        cin >> a[i];
    for (int i=1; i<=n; ++i)
        if (!vis[i])
            dfs(i);
    int c=n;
    for (int i=0; sz[i]; ++i)
        c-=sz[i], ans=(ans*(p[sz[i]]-2+M))%M;
    ans=(ans*p[c]+M)%M;
    cout << ans << '\n';
}

