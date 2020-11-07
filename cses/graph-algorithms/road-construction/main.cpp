#include <bits/stdc++.h>
using namespace std;
//DSU
const int mxN=1e5+1;
int n, m, maxsz, comp, par[mxN], sz[mxN];

void make(int v) {
    par[v]=v;
    sz[v]=1;
}

int find(int v) {
    return (v==par[v]?v:par[v]=find(par[v]));
}

void combine(int a, int b) {
    a=find(a), b=find(b);
    if (a!=b) {
        if (sz[a]<sz[b])
            swap(a, b);
        par[b]=a, sz[a]+=sz[b], --comp;
        maxsz=max(maxsz, sz[a]);
    }
}

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    comp=n;
    for (int i=1; i<=n; ++i)
        make(i);
    while (m--) {
        int a, b;
        cin >> a >> b;
        combine(a, b);
        cout << comp << " " << maxsz << '\n';
    }
}
