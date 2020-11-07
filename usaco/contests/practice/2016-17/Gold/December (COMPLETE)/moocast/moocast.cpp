#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
using pii=pair<int, int>;
//Yay worked first try with no debugging/compilation errors!
//Binsearch+DSU
ifstream fin("moocast.in");
ofstream fout("moocast.out");

const int mxN=1e3+1;
int n, par[mxN], sz[mxN], cur;
pii a[mxN];

int get_dist(pii a, pii b) {
    return (a.fi-b.fi)*(a.fi-b.fi)+(a.se-b.se)*(a.se-b.se);
}

void make(int v) {
    par[v]=v, sz[v]=1;
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
        par[b]=a, sz[a]+=sz[b], --cur;
    }
}

bool works(int x) {
    cur=n;
    for (int i=0; i<n; ++i)
        make(i);
    for (int i=0; i<n; ++i)
        for (int j=0; j<n; ++j)
            if (get_dist(a[i], a[j])<=x)
                merge(i, j);
    return (cur==1);
}

int main() {
    fin >> n;
    for (int i=0; i<n; ++i)
        fin >> a[i].fi >> a[i].se;
    int lo=0, hi=1e9;
    while (lo<hi) {
        int mid=(lo+hi)/2;
        if (works(mid))
            hi=mid;
        else
            lo=mid+1;
    }
    fout << lo << '\n';
}
