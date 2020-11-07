//Construct segtree that supports rmaxq and rminq of x- and y- values of all cows
//YAY worked first try
#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
using ll=long long;
using pii=pair<int, int>;

ifstream fin("split.in");
ofstream fout("split.out");

struct node {
    int xs, xl, ys, yl;
    node() {
        xs=ys=INT_MAX;
        xl=yl=INT_MIN;
    }
    node(int xs, int xl, int ys, int yl):xs(xs), xl(xl), ys(ys), yl(yl) {}
};

node combine(node a, node b) {
    node ans;
    ans.xs=min(a.xs, b.xs);
    ans.xl=max(a.xl, b.xl);
    ans.ys=min(a.ys, b.ys);
    ans.yl=max(a.yl, b.yl);
    return ans;
}

node make(pii a) {
    return node(a.fi, a.fi, a.se, a.se);
}

const int mxN=5e4+1;
int n;
ll whole, ans=0;
pii a1[mxN], a2[mxN];
node seg[mxN*4];

void build(pii arr[], int v=1, int l=0, int r=n-1) {
    if (l==r) {
        seg[v]=make(arr[l]);
        return;
    }
    int mid=(l+r)/2;
    build(arr, v*2, l, mid);
    build(arr, v*2+1, mid+1, r);
    seg[v]=combine(seg[v*2], seg[v*2+1]);
}

node query(int l, int r, int lo=0, int hi=n-1, int v=1) {
    if (l>hi || r<lo)
        return node();
    if (lo>=l && hi<=r)
        return seg[v];
    int mid=(lo+hi)/2;
    return combine(query(l, r, lo, mid, v*2), query(l, r, mid+1, hi, v*2+1));
}

bool cmp(pii a, pii b) {
    if (a.se!=b.se)
        return a.se<b.se;
    return a.fi<b.fi;
}

int main() {
    fin >> n;
    for (int i=0; i<n; ++i)
        fin >> a1[i].fi >> a1[i].se, a2[i]=a1[i];
    sort(a1, a1+n);
    sort(a2, a2+n, cmp);
    build(a1);
    node all=query(0, n-1);
    whole=1LL*(all.xl-all.xs)*(all.yl-all.ys);
    for (int t=0; t<2; ++t) {
        for (int i=0; i<n-1; ++i) {
            node a=query(0, i), b=query(i+1, n-1);
            ll cur1=1LL*(a.xl-a.xs)*(a.yl-a.ys),
               cur2=1LL*(b.xl-b.xs)*(b.yl-b.ys);
            ans=max(ans, whole-cur1-cur2);
        }
        build(a2);
    }
    fout << ans << '\n';
}
