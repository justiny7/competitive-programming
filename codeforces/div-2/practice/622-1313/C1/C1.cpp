#include <bits/stdc++.h>
#define pb push_back
using namespace std;
using ll=long long;

bool ckmax(ll& a, const ll& b) {
    return (a<b?a=b,1:0);
}

const int mxN=1e3+1;
ll n, a[mxN], cmax;
vector<ll> ans;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for (int i=0; i<n; ++i)
        cin >> a[i];
    for (int i=0; i<=n; ++i) {
        ll cur=0;
        vector<ll> l(i), r(n-i);
        if (i^n) {
            r[0]=a[i], cur+=r[0];
            for (int j=i+1; j<n; ++j)
                r[j-i]=min(a[j], r[j-i-1]), cur+=r[j-i];
        }
        if (i) {
            l[i-1]=min(r.size()?r[0]:LLONG_MAX, a[i-1]), cur+=l[i-1];
            for (int j=i-2; ~j; --j)
                l[j]=min(a[j], l[j+1]), cur+=l[j];
        }
        if (ckmax(cmax, cur)) {
            ans.clear();
            for (ll i:l)
                ans.pb(i);
            for (ll i:r)
                ans.pb(i);
        }
    }
    for (int i=0; i<n; ++i)
        cout << ans[i] << (i<n-1?" ":"\n");
}


