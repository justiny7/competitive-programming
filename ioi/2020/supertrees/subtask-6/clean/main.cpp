#include "supertrees.h"
#include <bits/stdc++.h>
#define eb emplace_back
using namespace std;
using vb=vector<bool>;
using vi=vector<int>;
using vvi=vector<vi>;

const int mxN=1e3+1;
int n;
vb vis;
vvi ans;

struct DSU {
    int par[mxN], sz[mxN];
    DSU() {
        for (int i=0; i<n; ++i)
            par[i]=i, sz[i]=1;
    }
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
    bool same(int a, int b) {
        return (find(a)==find(b));
    }
};

int construct(vvi p) {
    n=p.size();
    ans=vvi(n, vi(n));
    DSU d[4];
    for (int i=0; i<n; ++i)
        for (int j=0; j<n; ++j)
            if (p[i][j] && p[i][j]^2)
                d[p[i][j]].merge(i, j);
    for (int i=0; i<n; ++i)
        for (int j=0; j<n; ++j) {
            if (p[i][j]==2)
                d[2].merge(d[1].find(i), d[1].find(j));
            else if (!p[i][j]) {
                for (int k=1; k<4; ++k)
                    if (d[k].same(i, j))
                        return 0;
            }
        }
    vis=vb(n);
    for (int i=0; i<n; ++i) {
        if (vis[d[1].find(i)])
            continue;
        vis[d[1].find(i)]=1;
        for (int j=0; j<n; ++j)
            if (i^j && d[1].same(i, j)) {
                if (p[i]!=p[j])
                    return 0;
                ans[i][j]=ans[j][i]=1;
            }
    }
    vis=vb(n);
    for (int i=0; i<n; ++i) {
        if (vis[d[2].find(i)])
            continue;
        vis[d[2].find(i)]=1;
        vi v;
        for (int j=0; j<n; ++j)
            if (d[2].same(i, j))
                v.eb(j);
        int sz=v.size();
        if (sz==1)
            continue;
        if (sz==2)
            return 0;
        for (int j=0; j<sz; ++j) {
            if (j)
                ans[v[j]][v[j-1]]=ans[v[j-1]][v[j]]=1;
            if (j<sz-1)
                ans[v[j]][v[j+1]]=ans[v[j+1]][v[j]]=1;
        }
        ans[v[0]][v.back()]=ans[v.back()][v[0]]=1;
    }
    vis=vb(n);
    for (int i=0; i<n; ++i) {
        if (vis[d[3].find(i)])
            continue;
        vis[d[3].find(i)]=1;
        vi v;
        bool f=1;
        for (int j=0; j<n; ++j) {
            if (d[3].same(i, j))
                v.eb(j);
            if (i^j)
                f&=(p[i][j]==3 || !p[i][j]);
        }
        int sz=v.size();
        if (sz==1)
            continue;
        if (f || sz^4)
            return 0;
        ans[v[0]][v[1]]=ans[v[1]][v[0]]=1;
        ans[v[1]][v[2]]=ans[v[2]][v[1]]=1;
        ans[v[2]][v[3]]=ans[v[3]][v[2]]=1;
        ans[v[0]][v[3]]=ans[v[3]][v[0]]=1;
        ans[v[0]][v[2]]=ans[v[2]][v[0]]=1;
    }
    build(ans);
    return 1;
}
