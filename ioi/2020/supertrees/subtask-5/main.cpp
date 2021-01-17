#include "supertrees.h"
#include <bits/stdc++.h>
#define eb emplace_back
using namespace std;
using vi=vector<int>;
using vvi=vector<vi>;
 
const int mxN=1e3+1;
int n;
vvi ans;
 
struct DSU {
    int par[mxN], sz[mxN];
    DSU(int n) {
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
    DSU ones(n);
    for (int i=0; i<n; ++i)
        for (int j=0; j<n; ++j) {
            if (p[i][j]==1)
                ones.merge(i, j);
            else if (!p[i][j] && ones.same(i, j))
                return 0;
        }
    vector<bool> vis(n);
    for (int i=0; i<n; ++i) {
        if (vis[ones.find(i)])
            continue;
        vis[ones.find(i)]=1;
        vi v;
        for (int j=0; j<n; ++j)
            if (ones.same(i, j)) {
                if (p[i]!=p[j])
                    return 0;
                v.eb(j);
            }
        int sz=v.size();
        for (int j=0; j<sz; ++j) {
            if (j)
                ans[v[j]][v[j-1]]=ans[v[j-1]][v[j]]=1;
            if (j<sz-1)
                ans[v[j]][v[j+1]]=ans[v[j+1]][v[j]]=1;
        }
    }
    DSU twos(n);
    for (int i=0; i<n; ++i)
        for (int j=0; j<n; ++j) {
            if (p[i][j]==2)
                twos.merge(ones.find(i), ones.find(j));
            else if (!p[i][j] && twos.same(ones.find(i), ones.find(j)))
                return 0;
        }
    vis=vector<bool>(n);
    for (int i=0; i<n; ++i) {
        if (vis[twos.find(i)])
            continue;
        vis[twos.find(i)]=1;
        vi v;
        for (int j=0; j<n; ++j)
            if (twos.same(i, j))
                v.eb(j);
        int sz=v.size();
        for (int j=0; j<sz; ++j) {
            if (j)
                ans[v[j]][v[j-1]]=ans[v[j-1]][v[j]]=1;
            if (j<sz-1)
                ans[v[j]][v[j+1]]=ans[v[j+1]][v[j]]=1;
        }
        if (sz>2)
            ans[v[0]][v.back()]=ans[v.back()][v[0]]=1;
        else if (sz==2)
            return 0;
    }
    build(ans);
    return 1;
}

