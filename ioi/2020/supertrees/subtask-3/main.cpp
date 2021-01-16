#include "supertrees.h"
#include <bits/stdc++.h>
#define eb emplace_back
using namespace std;
using vi=vector<int>;
using vvi=vector<vi>;

const int mxN=1e3+1;
int n, par[mxN], sz[mxN];

int find(int v) {
    return (par[v]==v?v:par[v]=find(par[v]));
}
bool merge(int a, int b) {
    a=find(a), b=find(b);
    if (a==b)
        return 0;
    if (sz[a]>sz[b])
        swap(a, b);
    par[a]=b, sz[b]+=sz[a];
    return 1;
}

int construct(vvi p) {
    n=p.size();
    vvi ans(n, vi(n));
    for (int i=0; i<n; ++i)
        par[i]=i, sz[i]=1;
    bool f=0;
    for (int i=0; i<n; ++i)
        for (int j=0; j<n; ++j)
            if (p[i][j]) {
                merge(i, j);
                if (p[i][j]==2)
                    f=1;
            }
    vector<bool> vis(n);
    vvi grps;
    for (int i=0; i<n; ++i)
        for (int j=0; j<n; ++j)
            if (!p[i][j] && find(i)==find(j))
                return 0;
    for (int i=0; i<n; ++i) {
        if (vis[find(i)])
            continue;
        vis[find(i)]=1;
        vi here;
        for (int j=0; j<n; ++j)
            if (find(j)==find(i))
                here.eb(j);
        grps.eb(here);
    }
    for (vi v:grps) {
        int sz=v.size();
        for (int j=0; j<sz; ++j) {
            if (j)
                ans[v[j]][v[j-1]]=ans[v[j-1]][v[j]]=1;
            if (j<sz-1)
                ans[v[j]][v[j+1]]=ans[v[j+1]][v[j]]=1;
        }
        if (f) {
            if (sz>2)
                ans[v[0]][v.back()]=ans[v.back()][v[0]]=1;
            else if (sz==2)
                return 0;
        }
    }
    build(ans);
    return 1;
}

