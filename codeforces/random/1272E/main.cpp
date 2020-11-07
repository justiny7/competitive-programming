#include <bits/stdc++.h>
#define pb push_back
using namespace std;

const int mxN=2e5+1, INF=0x3f3f3f3f;
int n, a[mxN], st[mxN], d[mxN];
vector<int> adj[mxN];
queue<int> q;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for (int i=1; i<=n; ++i) {
        cin >> a[i];
        if (i+a[i]<=n)
            adj[i+a[i]].pb(i);
        if (i-a[i]>0)
            adj[i-a[i]].pb(i);
    }
    for (int t=0; t<2; ++t) {
        memset(st, 0x3f, sizeof(st));
        for (int i=1; i<=n; ++i)
            if ((a[i]&1)==t)
                q.push(i), st[i]=0;
        while (!q.empty()) {
            int v=q.front(); q.pop();
            for (int u:adj[v])
                if (st[u]==INF)
                    st[u]=st[v]+1, q.push(u);
        }
        for (int i=1; i<=n; ++i)
            if ((a[i]&1)^t)
                d[i]=st[i];
    }
    for (int i=1; i<=n; ++i)
        cout << (d[i]<INF?d[i]:-1) << (i<n?" ":"\n");
}

