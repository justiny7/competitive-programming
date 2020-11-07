#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
using pii=pair<int, int>;
using ll=long long;
//Ayy worked first try without any compilation errors and debugging!
//Idea: use DSU and add sections in decreasing height order
ifstream fin("poker.in");
ofstream fout("poker.out");

const int mxN=1e5+1;
int n, par[mxN], sz[mxN];
ll ans, cur;
pii c[mxN];
bool vis[mxN];

void make(int v) {
    par[v]=v, sz[v]=1, ++cur;
}

int find(int v) {
    if (v==par[v])
        return v;
    return par[v]=find(par[v]);
}

void combine(int a, int b) {
    a=find(a), b=find(b);
    if (a!=b) {
        if (sz[a]<sz[b])
            swap(a, b);
        par[b]=a, sz[a]+=sz[b], --cur;
    }
}

int main(void) {
    fin >> n;
    for (int i=0; i<n; ++i)
        fin >> c[i].fi, c[i].se=i;
    sort(c, c+n, greater<pii>());
    int j=0;
    for (int i=mxN-1; i>0; --i) {
        while (c[j].fi>=i) {
            vis[c[j].se]=1;
            make(c[j].se);
            if (c[j].se+1<n && vis[c[j].se+1])
                combine(c[j].se, c[j].se+1);
            if (c[j].se-1>=0 && vis[c[j].se-1])
                combine(c[j].se, c[j].se-1);
            ++j;
        }
        ans+=cur;
    }
    fout << ans << '\n';
}
