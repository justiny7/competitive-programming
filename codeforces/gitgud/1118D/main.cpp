#include <bits/stdc++.h>
using namespace std;
using ll=long long;

const int mxN=2e5+1;
ll n, m, a[mxN];

bool ok(ll x) {
    ll amt=0;
    for (int i=0; i<n; ++i)
        amt+=max(0LL, a[i]-i/x);
    return (amt>=m);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    for (int i=0; i<n; ++i)
        cin >> a[i];
    sort(a, a+n, greater<ll>());
    ll lo=1, hi=1e9, best=-1;
    while (lo<=hi) {
        ll m=lo+hi>>1;
        if (ok(m))
            best=m, hi=m-1;
        else
            lo=m+1;
    }
    cout << best << '\n';
}

