#include <bits/stdc++.h>
using namespace std;

const int mxN=2e5+1;
int n, q, r;
struct mat {
    int a[2][2];
    mat() {}
    mat(int p, int q, int r, int s) {
        a[0][0]=p, a[0][1]=q;
        a[1][0]=r, a[1][1]=s;
    }
    mat& operator=(const mat& m) {
        for (int i=0; i<2; ++i)
            for (int j=0; j<2; ++j)
                a[i][j]=m.a[i][j];
        return *this;
    }
    mat operator*(const mat& m) {
        mat ans;
        ans.a[0][0]=(a[0][0]*m.a[0][0]+a[0][1]*m.a[1][0])%r;
        ans.a[0][1]=(a[0][0]*m.a[0][1]+a[0][1]*m.a[1][1])%r;
        ans.a[1][0]=(a[1][0]*m.a[0][0]+a[1][1]*m.a[1][0])%r;
        ans.a[1][1]=(a[1][0]*m.a[0][1]+a[1][1]*m.a[1][1])%r;
        return ans;
    }
    void print() {
        for (int i=0; i<2; ++i)
            cout << a[i][0] << " " << a[i][1] << '\n';
        cout << '\n';
    }
} seg[mxN*4];
const mat id(1, 0, 0, 1);

void upd(int i, mat& m, int l=0, int r=n-1, int v=1) {
    if (l==r) {
        seg[v]=m;
        return;
    }
    int mid=l+r>>1;
    if (i<=mid)
        upd(i, m, l, mid, v<<1);
    else
        upd(i, m, mid+1, r, v<<1|1);
    seg[v]=seg[v<<1]*seg[v<<1|1];
}
mat query(int l, int r, int lo=0, int hi=n-1, int v=1) {
    if (l>hi || r<lo)
        return id;
    if (lo>=l && hi<=r)
        return seg[v];
    int mid=lo+hi>>1;
    return query(l, r, lo, mid, v<<1)*query(l, r, mid+1, hi, v<<1|1);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> r >> n >> q;
    for (int i=0; i<n; ++i) {
        int p, q, r, s;
        cin >> p >> q >> r >> s;
        mat m(p, q, r, s);
        upd(i, m);
    }
    while (q--) {
        int l, r;
        cin >> l >> r;
        mat m=query(l-1, r-1);
        m.print();
    }
}

