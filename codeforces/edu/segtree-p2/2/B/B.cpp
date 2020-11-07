#include <bits/stdc++.h>
using namespace std;
using ll=long long;

const int mxN=1e5+1;
const ll M=1e9+7;
int n, q;
ll t[mxN<<2], lz[mxN<<2];

void build(int v=1, int l=0, int r=n-1) {
    if (l==r) {
        t[v]=1;
        return;
    }
    int m=l+r>>1;
    build(v<<1, l, m);
    build(v<<1|1, m+1, r);
    t[v]=t[v<<1]+t[v<<1|1];
}
void push(int v, int l, int r) {
    if (l^r) {
        lz[v<<1]=lz[v<<1]*lz[v]%M;
        lz[v<<1|1]=lz[v<<1|1]*lz[v]%M;
        t[v<<1]=t[v<<1]*lz[v]%M;
        t[v<<1|1]=t[v<<1|1]*lz[v]%M;
    }
    lz[v]=1;
}
void upd(int l, int r, ll x, int lo=0, int hi=n-1, int v=1) {
    if (l>hi || r<lo)
        return;
    if (lo>=l && hi<=r) {
        t[v]=t[v]*x%M, lz[v]=lz[v]*x%M;
        return;
    }
    push(v, lo, hi);
    int m=lo+hi>>1;
    upd(l, r, x, lo, m, v<<1);
    upd(l, r, x, m+1, hi, v<<1|1);
    t[v]=(t[v<<1]+t[v<<1|1])%M;
}
ll query(int l, int r, int lo=0, int hi=n-1, int v=1) {
    if (l>hi || r<lo)
        return 0;
    if (lo>=l && hi<=r)
        return t[v];
    push(v, lo, hi);
    int m=lo+hi>>1;
    return (query(l, r, lo, m, v<<1)+query(l, r, m+1, hi, v<<1|1))%M;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> q;
    fill(lz, lz+(n<<2), 1);
    build();
    while (q--) {
        int a, b, c;
        cin >> a >> b >> c, --c;
        if (a==1) {
            int d; cin >> d;
            upd(b, c, d);
        }
        else
            cout << query(b, c)%M << '\n';
    }
}


