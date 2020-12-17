#include <bits/stdc++.h>
#define pb push_back
using namespace std;

const int mxN=3e5+1;
int n, k, head[mxN], par[mxN], nxt[mxN], pre[mxN], pos[mxN], in[mxN];
vector<int> chains[mxN], adj[mxN], topo;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> k;
    for (int i=1; i<=n; ++i)
        cin >> par[i];
    for (int i=0; i<k; ++i) {
        int a, b;
        cin >> a >> b;
        if (nxt[a] || pre[b])
            return cout << "0\n", 0;
        nxt[a]=b, pre[b]=a;
    }
    for (int i=1; i<=n; ++i) {
        if (pre[i])
            continue;
        int cur=i, c=0;
        head[i]=i, pos[i]=c++;
        chains[i].pb(i);
        while (nxt[cur])
            chains[i].pb(cur=nxt[cur]), head[cur]=i, pos[cur]=c++;
    }
    {
        set<int> temp[mxN];
        for (int i=1; i<=n; ++i) {
            if (!head[i])
                return cout << "0\n", 0;
            if (head[par[i]]^head[i])
                temp[head[par[i]]].insert(head[i]);
            else {
                if (pos[par[i]]>pos[i])
                    return cout << "0\n", 0;
            }
        }
        for (int i=1; i<=n; ++i)
            for (int j:temp[i])
                adj[i].pb(j), ++in[j];
    }
    queue<int> q;
    for (int i=1; i<=n; ++i)
        if (!in[i])
            q.push(i);
    while (q.size()) {
        int v=q.front(); q.pop();
        topo.pb(v);
        for (int u:adj[v])
            if (in[u]) {
                --in[u];
                if (!in[u])
                    q.push(u);
            }
    }
    if (topo.size()<n)
        return cout << "0\n", 0;
    for (int i:topo)
        for (int j:chains[i])
            cout << j << " ";
    cout << '\n';
}

