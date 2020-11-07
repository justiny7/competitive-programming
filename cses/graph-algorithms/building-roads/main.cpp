#include <bits/stdc++.h>
#define pb push_back
using namespace std;

int n, m, groups[100001], head[100001], num=1;
vector<int> adj[100001];

void dfs(int cur) {
    if (groups[cur]==num)
        return;
    groups[cur]=num;
    for (int u : adj[cur])
        dfs(u);
}

int main(void) {
    cin >> n >> m;
    for (int i=0; i<m; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    for (int i=1; i<=n; ++i) {
        if (groups[i]>0)
            continue;
        dfs(i);
        head[num]=i;
        num++;
    }
    cout << num-2 << '\n';
    for (int i=2; i<num; i++)
        cout << head[1] << " " << head[i] << '\n';
}
