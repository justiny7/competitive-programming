#include <bits/stdc++.h>
using namespace std;
using ll=long long;

const int mxN=2e5+1;
ll n, k, a[mxN];

bool works(ll x) {
    ll c=1, sum=0;
    for (int i=0; i<n; ++i) {
        if (a[i]+sum<=x)
            sum+=a[i];
        else if (a[i]<=x)
            sum=a[i], ++c;
        if (c>k || a[i]>x)
            return 0;
    }
    return 1;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> k;
    for (int i=0; i<n; ++i)
        cin >> a[i];
    ll lo=1, hi=2e14;
    while (lo<hi) {
        ll mid=(lo+hi)/2;
        if (works(mid))
            hi=mid;
        else
            lo=mid+1;
    }
    cout << lo << '\n';
}
