#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
using ll=long long;
using pll=pair<ll, ll>;

bool works(ll x, vector<pll>& a, ll tot) {
    int n=a.size(), cur=0;
    vector<pll> v;
    for (int i=0; i<n; ++i) {
        if (a[i].fi>=x)
            tot-=a[i].fi, ++cur;
        else if (a[i].se<x)
            tot-=a[i].fi;
        else
            v.push_back(a[i]);
    }
    sort(v.begin(), v.end(), [](pll p, pll q) { return p.fi>q.fi; });
    for (int i=0; i<v.size(); ++i) {
        if (cur<=n/2)
            ++cur, tot-=x;
        else
            tot-=v[i].fi;
    }
    return (tot>=0 && cur>n/2);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        ll s; cin >> s;
        vector<pll> a(n);
        for (pll& p:a)
            cin >> p.fi >> p.se;
        ll lo=1, hi=s;
        while (lo<hi) {
            ll mid=lo+hi+1>>1;
            if (works(mid, a, s))
                lo=mid;
            else
                hi=mid-1;
        }
        cout << lo << '\n';
    }
}

