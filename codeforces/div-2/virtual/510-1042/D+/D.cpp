#include <bits/stdc++.h>
using namespace std;
using ll=long long;

const int mxN=2e5+5;
ll n, mx, a[mxN], pref[mxN], bit[mxN];
set<ll, greater<ll>> vals;
map<ll, int> mp;

void upd(int i, ll x) {
    for (++i; i<=vals.size(); i+=i&-i)
        bit[i]+=x;
}

ll query(int i) {
    ll ans=0;
    for (++i; i>0; i-=i&-i)
        ans+=bit[i];
    return ans;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> mx;
    for (int i=1; i<=n; ++i) {
        cin >> a[i], pref[i]=a[i]+pref[i-1];
        vals.insert(pref[i]);
    }
    vals.insert(LLONG_MAX);
    vals.insert(0);
    int cur=0;
    for (ll i:vals)
        mp[i]=cur++;
    ll ans=0;
    upd(mp[0], 1);
    for (int i=1; i<=n; ++i) {
        ans+=query((mp.upper_bound(pref[i]-mx))->second);
        upd(mp[pref[i]], 1);
    }
    cout << ans << '\n';
}

