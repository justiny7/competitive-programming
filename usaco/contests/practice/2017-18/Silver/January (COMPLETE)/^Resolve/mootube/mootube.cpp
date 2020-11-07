//Yay worked first try
#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
using namespace std;
using pii=pair<int, int>;

const int mxN=5e3+1;
int n, q;
vector<pii> adj[mxN];

int dfs(int v, int k, int p=0) {
    int cur=1;
    for (pii u:adj[v])
        if (u.fi^p && u.se>=k)
            cur+=dfs(u.fi, k, v);
    return cur;
}

int main() {
    ifstream cin("mootube.in");
    ofstream cout("mootube.out");
    cin >> n >> q;
    for (int i=1; i<n; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].pb(pii(b, c));
        adj[b].pb(pii(a, c));
    }
    while (q--) {
        int k, v;
        cin >> k >> v;
        cout << dfs(v, k)-1 << '\n';
    }
}

