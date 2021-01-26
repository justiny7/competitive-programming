#include <bits/stdc++.h>
using namespace std;

const int mxN=1e5+1;
int n, k, pos[mxN], par[mxN];
set<int> vis[mxN];

int find(int v) {
    return (v==par[v]?v:par[v]=find(par[v]));
}
bool merge(int a, int b) {
    a=find(a), b=find(b);
    if (a==b)
        return 0;
    if (vis[a].size()>vis[b].size())
        swap(a, b);
    for (int i:vis[a])
        vis[b].insert(i);
    par[a]=b;
    vis[a].clear();
    return 1;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> k;
    for (int i=1; i<=n; ++i)
        pos[i]=par[i]=i, vis[i].insert(i);
    for (int i=0; i<k; ++i) {
        int a, b;
        cin >> a >> b;
        swap(pos[a], pos[b]);
        vis[pos[a]].insert(a);
        vis[pos[b]].insert(b);
    }
    for (int i=1; i<=n; ++i)
        merge(i, pos[i]);
    for (int i=1; i<=n; ++i)
        cout << vis[find(i)].size() << '\n';
}

