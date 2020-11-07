#include <bits/stdc++.h>
#define pb push_back
using namespace std;

const int mxN=1e5+1;
int n, q;
vector<int> v1, v2;

struct seg {
    int t[mxN*2], sz;
    seg(vector<int>& a) {
        memset(t, 0, sizeof(t));
        sz=a.size();
        for (int i=0; i<sz; ++i)
            upd(i, a[i]);
    }
    void upd(int i, int x, int l, int r, int v) {
        if (l==r) {
            t[v]=x;
            return;
        }
        int m=l+r>>1;
        if (i<=m)
            upd(i, x, l, m, v<<1);
        else
            upd(i, x, m+1, r, v<<1|1);
        t[v]=t[v<<1]+t[v<<1|1];
    }
    void upd(int i, int x) {
        upd(i, x, 0, sz-1, 1);
    }
    int query(int l, int r, int lo, int hi, int v) {
        if (hi<0)
            hi=sz-1;
        if (l>hi || r<lo)
            return 0;
        if (lo>=l && hi<=r)
            return t[v];
        int m=lo+hi>>1;
        return query(l, r, lo, m, v<<1)+query(l, r, m+1, hi, v<<1|1);
    }
    int query(int l, int r) {
        return query(l, r, 0, sz-1, 1);
    }
    void print() {
        for (int i=0; i<sz<<2; ++i)
            cout << t[i] << " ";
        cout << '\n';
    }
};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for (int i=0; i<n; ++i) {
        int a; cin >> a;
        ((i&1)?v1:v2).pb(a);
    }
    seg s1(v1), s2(v2);
    cin >> q;
    while (q--) {
        int a, b, c;
        cin >> a >> b >> c, --b;
        if (a) {
            --c;
            int b1=(b&1)?b>>1:b+1>>1, b2=(b&1)?b+1>>1:b>>1,
                e1=(c&1)?c>>1:c-1>>1, e2=(c&1)?c-1>>1:c>>1;
            if (b&1)
                cout << s1.query(b1, e1)-s2.query(b2, e2) << '\n';
            else
                cout << s2.query(b2, e2)-s1.query(b1, e1) << '\n';
        }
        else
            ((b&1)?s1:s2).upd(b>>1, c);
    }
}

