#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//Bruh it took me 4 submissions to figure out how to not overflow -_-
ll n, t, a[200001];

bool works(ll x) {
    ll c=0;
    for (int i=0; i<n; ++i)
        c+=min(x/a[i], (ll)1e9);
    return (c>=t);
}

int main(void) {
    cin >> n >> t;
    for (int i=0; i<n; ++i)
        cin >> a[i];
    ll lo=1, hi=1e18, best;
    while (lo<=hi) {
        ll mid=lo+(hi-lo)/2;
        if (works(mid)) {
            best=mid;
            hi=mid-1;
        }
        else
            lo=mid+1;
    }
    cout << best << '\n';
}
