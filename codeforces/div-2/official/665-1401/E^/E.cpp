#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
using ll=long long;

const int mxN=1e5+1, mxV=1e6+5;
int n, m, bit[mxV];
ll ans=1;
pair<int, pair<int, int>> h[mxN], v[2*mxN];

void upd(int i, int x) {
    for (++i; i<mxV; i+=i&-i)
        bit[i]+=x;
}
int query(int i) {
    int ret=0;
    for (++i; i>0; i-=i&-i)
        ret+=bit[i];
    return ret;
}
int query(int l, int r) {
    return query(r)-query(l-1);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    for (int i=0; i<n; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        h[i]={a, {b, c}};
        if (c-b>=1e6)
            ++ans;
    }
    sort(h, h+n);
    for (int i=0; i<m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        v[2*i]={b, {a, 0}};
        v[2*i+1]={c+1, {a, 1}};
        if (c-b>=1e6)
            ++ans;
    }
    sort(v, v+2*m);
    for (int i=0, j=0; i<n; ++i) {
        while (j<2*m && v[j].fi<=h[i].fi)
            upd(v[j].se.fi, (v[j].se.se?-1:1)), ++j;
        ans+=(ll)query(h[i].se.fi, h[i].se.se);
    }
    cout << ans << '\n';
}

