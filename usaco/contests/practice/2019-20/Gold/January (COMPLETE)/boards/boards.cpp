//This took forever to debug but I finally got it xd
#include <bits/stdc++.h>
using namespace std;

const int mxN=1e5+1;
int n, mx, dist[mxN], seg[mxN*4];
set<int> ys;
map<int, int> mp;
struct pt {
    int x, y, id, en;
    bool operator<(const pt& p) const {
        if (x^p.x)
            return x<p.x;
        if (y^p.y)
            return y<p.y;
        return en>p.en;
    }
} a[mxN*2];

void upd(int i, int x, int l=0, int r=n-1, int v=1) {
    if (l==r) {
        seg[v]=min(seg[v], x);
        return;
    }
    int mid=(l+r)/2;
    if (i<=mid)
        upd(i, x, l, mid, v*2);
    else
        upd(i, x, mid+1, r, v*2+1);
    seg[v]=min(seg[v*2], seg[v*2+1]);
}

int query(int l, int r, int lo=0, int hi=n-1, int v=1) {
    if (l>hi || r<lo)
        return INT_MAX;
    if (lo>=l && hi<=r)
        return seg[v];
    int mid=(lo+hi)/2;
    return min(query(l, r, lo, mid, v*2), query(l, r, mid+1, hi, v*2+1));
}

int main() {
    ifstream cin("boards.in");
    ofstream cout("boards.out");
    cin >> mx >> n;
    for (int i=0; i<n*2; ++i) {
        cin >> a[i].x >> a[i].y, a[i].en=(i&1)?1:0, a[i].id=i/2;
        if (i&1)
            ys.insert(a[i].y);
    }
    sort(a, a+n*2);
    int cur=1;
    for (int i:ys)
        mp[i]=cur++;
    for (int i=0; i<n*2; ++i) {
        if (a[i].en)
            upd(mp[a[i].y], dist[a[i].id]-a[i].x-a[i].y);
        else {
            auto it=mp.upper_bound(a[i].y);
            dist[a[i].id]=query(0, (it==mp.begin()?0:(--it)->second))+a[i].x+a[i].y;
        }
    }
    cout << mx*2+query(0, cur-1) << '\n';
}

