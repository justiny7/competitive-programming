#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
using namespace std;
using pii=pair<int, int>;

const int mxN=1e5+1, mxM=2e5+1;
int n, m, k, cnt, par[mxN], sz[mxN];
vector<int> ans;
vector<pii> e, rm;
set<pii> s;

int find(int v) {
    return (par[v]==v?v:par[v]=find(par[v]));
}
void merge(int a, int b) {
    a=find(a), b=find(b);
    if (a^b) {
        if (sz[a]<sz[b])
            swap(a, b);
        par[b]=a, sz[a]+=sz[b], --cnt;
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m >> k;
    for (int i=0; i<m; ++i) {
        int a, b;
        cin >> a >> b;
        e.pb(minmax(a, b));
    }
    for (int i=0; i<k; ++i) {
        int a, b;
        cin >> a >> b;
        rm.pb(minmax(a, b));
        s.insert(minmax(a, b));
    }
    for (int i=1; i<=n; ++i)
        par[i]=i, sz[i]=1, ++cnt;
    for (pii p:e)
        if (!s.count(p))
            merge(p.fi, p.se);
    for (int i=k-1; ~i; --i)
        ans.pb(cnt), merge(rm[i].fi, rm[i].se);
    for (int i=k-1; ~i; --i)
        cout << ans[i] << (i?" ":"\n");
}

