#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
using namespace std;
using pii=pair<int, int>;
//Yay worked first try
ifstream fin("crowded.in");
ofstream fout("crowded.out");

const int mxN=5e4+1;
int n, d, seg[mxN*4], ans;
pii a[mxN];

void build(int v=1, int l=0, int r=n-1) {
    if (l==r)
        seg[v]=a[l].se;
    else {
        int mid=(l+r)/2;
        build(v*2, l, mid);
        build(v*2+1, mid+1, r);
        seg[v]=max(seg[v*2], seg[v*2+1]);
    }
}

int query(int l, int r, int li=0, int ri=n-1, int v=1) {
    if (l>r)
        return -1;
    if (l==li && r==ri)
        return seg[v];
    int mid=(li+ri)/2;
    return max(query(l, min(mid, r), li, mid, v*2), query(max(mid+1, l), r, mid+1, ri, v*2+1));
}

int main(void) {
    fin >> n >> d;
    for (int i=0; i<n; ++i)
        fin >> a[i].fi >> a[i].se;
    sort(a, a+n);
    build();
    for (int i=1; i<n-1; ++i) {
        int l=lower_bound(a, a+n, mp(a[i].fi-d, 0))-a;
        int r=lower_bound(a, a+n, mp(a[i].fi+d, 0))-a;
        if (r==n)
            --r;
        if (query(l, i)>=2*a[i].se && query(i, r)>=2*a[i].se)
            ++ans;
    }
    fout << ans << '\n';
}
