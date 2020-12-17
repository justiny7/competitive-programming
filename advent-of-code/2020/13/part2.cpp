#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
using ll=long long;
using pll=pair<ll, ll>;

ll gcd(ll a, ll b) {
    return (b?gcd(b, a%b):a);
}
ll lcm(ll a, ll b) {
    return (a/gcd(a, b)*b);
}

int main() {
    freopen("test.txt", "r", stdin);
    int t; cin >> t;
    string s; cin >> s;
    vector<pll> v;
    for (ll i=0, c=0, cur=0; i<s.size(); ++i) {
        if (s[i]>='0' && s[i]<='9')
            cur=cur*10+(s[i]-'0');
        if (s[i]==',' || i==s.size()-1) {
            if (cur)
                v.emplace_back(cur, c), cur=0;
            ++c;
        }
    }
    ll cur=0, step=v[0].fi, ind=1;
    while (1) {
        cur+=step;
        if ((cur+v[ind].se)%v[ind].fi==0)
            step=lcm(step, v[ind].fi), ++ind;
        if (ind==v.size())
            return cout << cur << '\n', 0;
    }
}

