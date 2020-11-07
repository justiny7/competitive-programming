#include <bits/stdc++.h>
#define pb push_back
using namespace std;

int n, m, team[100001], t=1, num=1;
vector<int> adj[100001];
bool flag;

void dfs(int cur, int last) {
    if (team[cur]>0)
        return;
    last=(last==1)?2:1;
    team[cur]=last;
    for (int u : adj[cur]) {
        if (team[u]==0)
            dfs(u, last);
        else
            if (team[u]==last) {
                flag=1;
                return;
            }
        if (flag)
            return;
    }
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
        if (team[i]>0)
            continue;
        dfs(i, 1);
        if (flag)
            break;
    }
    if (flag)
        cout << "IMPOSSIBLE\n";
    else
        for (int i=1; i<=n; ++i) {
            if (i>1)
                cout << " ";
            cout << team[i];
        }
    cout << '\n';
}
