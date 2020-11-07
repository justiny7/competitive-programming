#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
using namespace std;
using pii=pair<int, int>;
//wtf this worked first try I'm shook 
const int mxN=5e5+1;
int n, m, grp[mxN];
pii t[mxN];
vector<int> adj[mxN], ans;

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i=0; i<m; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    for (int i=1; i<=n; ++i) {
        int a;
        cin >> a;
        t[i]={a, i};
    }
    sort(t+1, t+n+1);
    for (int i=1; i<=n; ++i) {
        set<int> taken;
        for (int u : adj[t[i].se])
            taken.insert(grp[u]);
        int cur=1;
        while (taken.find(cur)!=taken.end())
            cur++;
        grp[t[i].se]=cur;
        if (grp[t[i].se]!=t[i].fi) {
            cout << "-1\n";
            return 0;
        }
        else
            ans.pb(t[i].se);
    }
    for (int& i : ans)
        cout << i << " ";
    cout << '\n';
}
