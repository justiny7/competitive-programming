//Yay got it second try when I realized that the toposort had to be lexographically smallest xd
#include <bits/stdc++.h>
#define pb push_back
using namespace std;

const int mxN=1e5+1, mxM=2e5+1;
int n, m;
vector<int> adj[mxN], orders[mxM], topo, in;
priority_queue<int, vector<int>, greater<int>> pq;

bool works(int x) {
    topo.clear();
    in=vector<int>(n+1);
    for (int i=1; i<=n; ++i)
        adj[i].clear();
    for (int i=0; i<=x; ++i)
        for (int j=1; j<orders[i].size(); ++j)
            adj[orders[i][j-1]].pb(orders[i][j]), ++in[orders[i][j]];
    for (int i=1; i<=n; ++i)
        if (!in[i])
            pq.push(i);
    int cur=0;
    while (!pq.empty()) {
        int v=pq.top(); pq.pop();
        topo.pb(v);
        for (int u:adj[v])
            if (!--in[u])
                pq.push(u);
        ++cur;
    }
    return (cur==n);
}

int main() {
    ifstream cin("milkorder.in");
    ofstream cout("milkorder.out");
    cin >> n >> m;
    for (int i=0; i<m; ++i) {
        int t; cin >> t;
        orders[i].resize(t);
        for (int j=0; j<t; ++j)
            cin >> orders[i][j];
    }
    int lo=0, hi=m-1;
    while (lo<hi) {
        int mid=(lo+hi+1)/2;
        if (works(mid))
            lo=mid;
        else
            hi=mid-1;
    }
    works(lo);
    for (int i=0; i<n; ++i) {
        if (i)
            cout << " ";
        cout << topo[i];
    }
    cout << '\n';
}

