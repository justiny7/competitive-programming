#include <bits/stdc++.h>
#define pb push_back
using namespace std;

const int mxN=1e5+1;
int n, m, in[mxN], out[mxN];
vector<int> adj[mxN], ans;

void go(int v=1) {
    while (!adj[v].empty()) {
        int u=adj[v].back();
        adj[v].pop_back();
        go(u);
    }
    ans.pb(v);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    while (m--) {
        int a, b;
        cin >> a >> b;
        adj[a].pb(b);
        ++in[b], ++out[a];
    }
    bool f=0;
    if (in[1]!=out[1]-1)
        f=1;
    if (out[n]!=in[n]-1)
        f=1;
    for (int i=2; i<=n-1; ++i)
        if (in[i]!=out[i]) {
            f=1;
            break;
        }
    if (f) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }
    go();
    for (int i=1; i<=n; ++i)
        if (!adj[i].empty()) {
            cout << "IMPOSSIBLE\n";
            return 0;
        }
    for (int i=ans.size()-1; i>=0; --i) {
        cout << ans[i];
        if (i)
            cout << " ";
    }
    cout << '\n';
}
