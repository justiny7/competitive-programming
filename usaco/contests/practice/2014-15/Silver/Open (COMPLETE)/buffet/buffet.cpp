//USACO Silver US Open 2015 Problem 3
#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
using pii=pair<int, int>;
//Kind of hard to get started - peeked at solution
ifstream fin("buffet.in");
ofstream fout("buffet.out");

int n, e, ans, dist[1001], maxat[1001];
pii q[1001];
vector<int> adj[1001];

bool cmp(pii a, pii b) {
    if (a.fi!=b.fi)
        return a.fi>b.fi;
    return a.se<b.se;
}

int main(void) {
    fin >> n >> e;
    for (int i=1; i<=n; ++i) {
        int a;
        fin >> q[i].fi >> a;
        q[i].se=i;
        adj[i].resize(a);
        for (int j=0; j<a; ++j)
            fin >> adj[i][j];
    }
    sort(q+1, q+n+1, cmp);
    for (int i=1; i<=n; ++i) {
        memset(dist, 0, sizeof(dist));
        int cur=q[i].se, curmax=q[i].fi;
        queue<int> qu;
        qu.push(cur);
        while (!qu.empty()) {
            int t=qu.front();
            qu.pop();
            for (int& i : adj[t])
                if (!dist[i] && i!=cur) {
                    dist[i]=dist[t]+1;
                    qu.push(i);
                }
        }
        for (int j=1; j<=n; ++j)
            if (dist[j])
                curmax=max(curmax, q[i].fi+maxat[j]-e*dist[j]);
        maxat[cur]=curmax;
        ans=max(ans, curmax);
    }
    fout << ans << '\n';
}
