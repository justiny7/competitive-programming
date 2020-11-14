#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
using db=double;
using pii=pair<int, int>;

int n, z;
db k;
vector<pii> turtles;

struct segtree {
    vector<int> t;
    int sz;
    segtree(vector<int> &v) {
        sz=v.size();
        t.resize(sz<<2);
        build(0, sz-1, 1, v);
    }
    void build(int l, int r, int v, vector<int> &a) {
        if (l==r) {
            t[v]=a[l];
            return;
        }
        int m=l+r>>1;
        build(l, m, v<<1, a);
        build(m+1, r, v<<1|1, a);
        t[v]=min(t[v<<1], t[v<<1|1]);
    }
    int query(int l, int r, int lo, int hi, int v) {
        if (l>hi || r<lo)
            return INT_MAX;
        if (lo>=l && hi<=r)
            return t[v];
        int m=lo+hi>>1;
        return min(query(l, r, lo, m, v<<1), query(l, r, m+1, hi, v<<1|1));
    }
    int query(int l, int r) {
        return query(l, r, 0, sz-1, 1);
    }
};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> z >> k;
    for (int i=0; i<n; ++i) {
        int x, y;
        cin >> x >> y;
        turtles.push_back(pii(y, x));
    }
    sort(turtles.begin(), turtles.end());
    vector<int> cur(z+1, INT_MAX);
    cur[turtles[0].se]=0;
    segtree s(cur);
    for (int i=1; i<n; ++i) {
        fill(cur.begin(), cur.end(), INT_MAX);
        int dif=(db)(turtles[i].fi-turtles[i-1].fi)/k;
        for (int j=1; j<=z; ++j) {
            int l=max(1, j-dif),
                r=min(z, j+dif),
                q=s.query(l, r);
            if (q^INT_MAX)
                cur[j]=q+abs(turtles[i].se-j);
        }
        s=segtree(cur);
    }
    cout << s.query(turtles[n-1].se, turtles[n-1].se) << '\n';
}

