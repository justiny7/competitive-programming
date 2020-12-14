#include <bits/stdc++.h>
using namespace std;

const int mxN=3e5+1;
int n, q, bit[mxN];

void upd(int i, int x) {
    for (; i<mxN; i+=i&-i)
        bit[i]^=x;
}
int query(int i) {
    int ret=0;
    for (; i; i-=i&-i)
        ret^=bit[i];
    return ret;
}
int query(int l, int r) {
    return (query(r)^query(l-1));
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> q;
    for (int i=1; i<=n; ++i) {
        int a; cin >> a;
        upd(i, a);
    }
    while (q--) {
        int t, x, y;
        cin >> t >> x >> y;
        if (t&1)
            upd(x, y);
        else
            cout << query(x, y) << '\n';
    }
}

