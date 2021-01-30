/*
Omg this problem was so confusing
 - The answer is sum(floor(a[i]-a[j])) where a[i]=# of revolutions a cow makes for all a[i]>a[j]
 - You get it by doing sum(floor(a[i])-floor(a[j])) and the subtracting out the ones where the
   fractional part of a[j] is greater than the fractional part of a[i]
 - The first part can be found by an easy formula - if a is sorted, a[i] get added i times
   and subtracted n-(i+1) times (base 0) for a total of (2*i-n+1)*a[i] contribution to the total
 - The second part can be calculated by keeping a running count of how many fractional parts have
   been seen under a certain modulo with a BIT and taking prefix queries and increment updates,
   coordinate compressing the mods
*/

#include <bits/stdc++.h>
using namespace std;
using ll=long long;

const int mxN=1e5+1;
ll n, l, c, mx, ans, bit[mxN];
void upd(int i) {
    for (; i<mxN; i+=i&-i)
        ++bit[i];
}
ll query(int i) {
    ll ret=0;
    for (; i; i-=i&-i)
        ret+=bit[i];
    return ret;
}
map<ll, ll> mp;
struct cow {
    ll s, p;
    bool operator<(const cow &o) const {
        return s<o.s;
    }
} cows[mxN];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> l >> c;
    for (int i=0; i<n; ++i)
        cin >> cows[i].s, mx=max(mx, cows[i].s);
    {
        set<ll> ss;
        for (int i=0; i<n; ++i) {
            cows[i].p=(l*c*cows[i].s)%(mx*c);
            ss.insert(cows[i].p);
        }
        int t=0;
        for (ll i:ss)
            mp[i]=++t;
    }
    sort(cows, cows+n);
    for (ll i=0; i<n; ++i) {
        ll rep=(l*cows[i].s)/mx;
        ans+=rep*(2*i-n+1)-i+query(mp[cows[i].p]);
        upd(mp[cows[i].p]);
    }
    cout << ans << '\n';
}

