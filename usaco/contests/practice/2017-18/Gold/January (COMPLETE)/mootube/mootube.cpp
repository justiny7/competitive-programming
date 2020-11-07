//Yes worked first try!
//DSU in decreasing query relevance
#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
using namespace std;
using pii=pair<int, int>;

ifstream fin("mootube.in");
ofstream fout("mootube.out");

const int mxN=1e5+1;
int n, q, ans[mxN], sz[mxN], par[mxN];
vector<pair<int, pii>> edges;
pair<pii, int> queries[mxN];

void make(int v) {
    sz[v]=1, par[v]=v;
}

int find(int v) {
    if (par[v]==v)
        return v;
    return par[v]=find(par[v]);
}

void merge(int a, int b) {
    a=find(a); b=find(b);
    if (a!=b) {
        if (sz[a]<sz[b])
            swap(a, b);
        sz[a]+=sz[b], par[b]=a;
    }
}

int main() {
    fin >> n >> q;
    for (int i=1; i<n; ++i) {
        int a, b, c;
        fin >> a >> b >> c;
        edges.pb({c, {a, b}});
    }
    sort(edges.begin(), edges.end(), greater<pair<int, pii>>());
    for (int i=0; i<q; ++i)
        fin >> queries[i].fi.fi >> queries[i].fi.se, queries[i].se=i;
    sort(queries, queries+q, greater<pair<pii, int>>());
    int ez=edges.size();
    for (int i=1; i<=n; ++i)
        make(i);
    for (int i=0, j=0; i<q || j<ez; ++i) {
        while (j<ez && edges[j].fi>=queries[i].fi.fi)
            merge(edges[j].se.fi, edges[j].se.se), ++j;
        ans[queries[i].se]=sz[find(queries[i].fi.se)];
    }
    for (int i=0; i<q; ++i)
        fout << ans[i]-1 << '\n';
}
