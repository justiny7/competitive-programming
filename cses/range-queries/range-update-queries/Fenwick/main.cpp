#include <bits/stdc++.h>
using namespace std;
using ll=long long;

const int mxN=2e5+1;
ll n, q, bit[mxN];

void add(int i, int x) {
    for (; i<=n; i+=i&(-i))
        bit[i]+=x;
}

void add(int l, int r, int x) {
    add(l, x);
    add(r+1, -x);
}

ll query(int i) {
    ll ans=0;
    for (; i>0; i-=i&(-i))
        ans+=bit[i];
    return ans;
}

int main(void) {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> q;
    for (int i=1; i<=n; ++i) {
        int a; cin >> a;
        add(i, i, a);
    }
    while (q--) {
        int t; cin >> t;
        if (t==1) {
            int a, b, c;
            cin >> a >> b >> c;
            add(a, b, c);
        }
        else {
            int k; cin >> k;
            cout << query(k) << '\n';
        }
    }
}
