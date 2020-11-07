#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
using ll=long long;
using pll=pair<ll, ll>;

const pll st[]={
    pll(1, 2),
    pll(-1, 2),
    pll(-2, 0),
    pll(-1, -2),
    pll(1, -2),
    pll(2, 0)
};
const pll d[]={
    pll(-2, 0),
    pll(-1, -2),
    pll(1, -2),
    pll(2, 0),
    pll(1, 2),
    pll(-1, 2),
};
ll n;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    ll lo=0, hi=1e9;
    while (lo<hi) {
        ll m=lo+hi>>1;
        if (3LL*m*(m+1)>=n)
            hi=m;
        else
            lo=m+1;
    }
    n-=3*lo*(lo-1);
    if (n<lo) {
        cout << (lo*2-n) << " " << (n*2) << '\n';
        return 0;
    }
    n-=lo;
    int seg=0;
    while (n-lo>0)
        n-=lo, ++seg;
    cout << (lo*st[seg].fi+n*d[seg].fi) << " " << (lo*st[seg].se+n*d[seg].se) << '\n';
}

