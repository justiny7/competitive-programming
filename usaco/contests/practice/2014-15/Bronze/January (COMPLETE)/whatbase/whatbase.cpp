#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll num(ll x, ll base) {
    string s=to_string(x);
    ll power=1, ans=0;
    for (int i=s.size()-1; i>=0; --i)
        ans+=(s[i]-'0')*power, power*=base;
    return ans;
}

void solve(ll a, ll b) {
    set<pair<ll, int>> s1, s2;
    for (int i=10; i<=15000; ++i)
        s1.insert({num(a, i), i});
    for (int i=10; i<=15000; ++i) {
        int j=num(b, i);
        auto it=s1.lower_bound(make_pair(j, 0));
        if (it->first==j) {
            cout << it->second << " " << i << '\n';
            break;
        }
    }
}

int main(void) {
    freopen("whatbase.in", "r", stdin);
    freopen("whatbase.out", "w", stdout);
    int t; cin >> t;
    while (t--) {
        ll x, y;
        cin >> x >> y;
        solve(x, y);
    }
}
