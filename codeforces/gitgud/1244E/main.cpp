#include <bits/stdc++.h>
using namespace std;
using ll=long long;

const int mxN=1e5+1;
int n;
ll k, a[mxN], p[mxN], s[mxN];

bool ok(ll x) {
    ll mn=LLONG_MAX;
    for (int i=1; i<=n; ++i) {
        int l=lower_bound(a+1, a+n+1, a[i])-a-1,
            r=upper_bound(a+1, a+n+1, a[i]+x)-a;
        mn=min(mn, a[i]*l-(n+1-r)*(a[i]+x)-p[l]+s[r]);
        l=lower_bound(a+1, a+n+1, a[i]-x)-a-1;
        r=upper_bound(a+1, a+n+1, a[i])-a;
        mn=min(mn, (a[i]-x)*l-(n+1-r)*a[i]-p[l]+s[r]);
    }
    return (mn<=k);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> k;
    for (int i=1; i<=n; ++i)
        cin >> a[i];
    sort(a+1, a+n+1);
    for (int i=1; i<=n; ++i)
        p[i]=a[i]+p[i-1];
    for (int i=n; i; --i)
        s[i]=a[i]+s[i+1];
    ll lo=0, hi=1e9;
    while (lo<hi) {
        ll m=lo+hi>>1;
        if (ok(m))
            hi=m;
        else
            lo=m+1;
    }
    cout << lo << '\n';
}

