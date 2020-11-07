//Yay worked first try even though I way overkilled it
//Ok I changed a bit of code (before I binary searched for right end, this time I keep a right pointer)
#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
using ll=long long;
using pll=pair<ll, ll>;

ifstream fin("hayfeast.in");
ofstream fout("hayfeast.out");

const int mxN=1e5+1;
ll n, m, ans=1e18;
pll hay[mxN], seg[mxN*4];

pll merge(pll a, pll b) {
    pll ans;
    ans.fi=a.fi+b.fi;
    ans.se=max(a.se, b.se);
    return ans;
}

void build(int v=1, int l=0, int r=n-1) {
    if (l==r)
        seg[v]=hay[l];
    else {
        int mid=(l+r)/2;
        build(v*2, l, mid);
        build(v*2+1, mid+1, r);
        seg[v]=merge(seg[v*2], seg[v*2+1]);
    }
}

pll query(int l, int r, int lo=0, int hi=n-1, int v=1) {
    if (l>hi || r<lo)
        return {0, 0};
    if (lo>=l && hi<=r)
        return seg[v];
    int mid=(lo+hi)/2;
    return merge(query(l, r, lo, mid, v*2), query(l, r, mid+1, hi, v*2+1));
}

int main() {
    fin >> n >> m;
    for (int i=0; i<n; ++i)
        fin >> hay[i].fi >> hay[i].se;
    build();
    for (int i=0, j=0; i<n || j<n; ++i) { //go through each left end, keep pointer on right
        while (j<n && query(i, j++).fi<m);
        pll c=query(i, j);
        if (c.fi>=m)
            ans=min(ans, c.se);
    }
    fout << ans << '\n';
}
