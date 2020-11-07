//Cycle finding - yay worked first try
#include <bits/stdc++.h>
using namespace std;

const int mxN=1e5+1;
int n, a[mxN], vis[mxN], t=1, ans;
bool active[mxN];

void dfs(int v) {
    vis[v]=t++, active[v]=1;
    if (active[a[v]])
        ans+=t-vis[a[v]];
    else if (!vis[a[v]])
        dfs(a[v]);
    active[v]=0;
}

int main() {
    ifstream cin("shuffle.in");
    ofstream cout("shuffle.out");
    cin >> n;
    for (int i=1; i<=n; ++i)
        cin >> a[i];
    for (int i=1; i<=n; ++i)
        if (!vis[i])
            dfs(i);
    cout << ans << '\n';
}

