#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int n, k, mp[256];
ll ans;
map<ll, ll> cnt;
vector<ll> v;

inline ll hsh(string s) {
    ll a=0;
    for (int i=0; i<k; ++i)
        a=a*3+(mp[s[i]]);
    return a;
}
inline ll ch3(ll x) {
    return (x*(x-1)*(x-2)/6);
}

int main() {
    mp['S']=0, mp['E']=1, mp['T']=2;
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> k;
    for (int i=0; i<n; ++i) {
        string s; cin >> s;
        ++cnt[hsh(s)];
    }
    for (auto p:cnt)
        v.push_back(p.first), ans+=ch3(p.second);
    n=v.size();
    for (int i=0; i<n; ++i)
        for (int j=i+1; j<n; ++j) {
            ll x=v[i], y=v[j], nxt=0, p=1;
            for (int l=0; l<k; ++l) {
                if (x%3==y%3)
                    nxt+=p*(x%3);
                else
                    nxt+=p*(3-(x%3)-(y%3));
                x/=3, y/=3, p*=3;
            }
            ans+=cnt[v[i]]*cnt[v[j]]*cnt[nxt];
        }
    cout << ans/3 << '\n';
}

