#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
using pii=pair<int, int>;

const int mxN=1e5+1;
int n, m, a[mxN], par[mxN], sz[mxN];
pair<int, pii> wh[mxN];

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
    if (a^b) {
        if (sz[a]<sz[b])
            swap(a, b);
        sz[a]+=sz[b], par[b]=a;
    }
}

bool works(int x) {
    memset(par, 0, sizeof(par));
    memset(sz, 0, sizeof(sz));
    for (int i=1; i<=n; ++i)
        make(i);
    int j=m-1;
    while (wh[j].fi>=x)
        merge(wh[j].se.fi, wh[j].se.se), --j;
    for (int i=1; i<=n; ++i)
        if (find(i)!=find(a[i]))
            return 0;
    return 1;
}

int main() {
    ifstream cin("wormsort.in");
    ofstream cout("wormsort.out");
    cin >> n >> m;
    for (int i=1; i<=n; ++i)
        cin >> a[i];
    for (int i=0; i<m; ++i)
        cin >> wh[i].se.fi >> wh[i].se.se >> wh[i].fi;
    sort(wh, wh+m);
    int lo=1, hi=1e9+1;
    while (lo<hi) {
        int mid=(lo+hi+1)/2;
        if (works(mid))
            lo=mid;
        else
            hi=mid-1;
    }
    cout << (lo==1e9+1?-1:lo) << '\n';
}

