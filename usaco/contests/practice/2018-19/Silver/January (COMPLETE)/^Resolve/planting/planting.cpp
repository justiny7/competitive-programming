//Yay worked first try
#include <bits/stdc++.h>
#define pb push_back
using namespace std;

const int mxN=1e5+1;
int n;
vector<int> adj[mxN];

int main() {
    ifstream cin("planting.in");
    ofstream cout("planting.out");
    cin >> n;
    for (int i=1; i<n; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    int ans=0;
    for (int i=1; i<=n; ++i)
        ans=max(ans, (int)adj[i].size());
    cout << ans+1 << '\n';
}

