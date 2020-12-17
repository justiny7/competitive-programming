#include <bits/stdc++.h>
using namespace std;
using ll=long long;

map<ll, ll> mp;

int main() {
    freopen("test.txt", "r", stdin);
    string s, msk;
    while (1) {
        getline(cin, s);
        if (s.empty())
            break;
        stringstream ss(s);
        string type;
        ss >> type;
        if (type[1]=='a')
            ss >> type >> msk;
        else {
            ll val, ind=0;
            ss >> type >> val;
            for (int i=4; s[i]^']'; ++i)
                ind=ind*10+(s[i]-'0');
            for (int i=0; i<36; ++i) {
                if (msk[35-i]=='1')
                    val|=(1LL<<i);
                else if (msk[35-i]=='0')
                    val&=(~(1LL<<i));
            }
            mp[ind]=val;
        }
    }
    ll ans=0;
    for (auto p:mp)
        ans+=p.second;
    cout << ans << '\n';
}

