#include <bits/stdc++.h>
using namespace std;
using ll=long long;

map<ll, ll> mp;
vector<ll> nxt;

void process(string &s, int i=0, ll cur=0) {
    if (i==s.size()) {
        nxt.push_back(cur);
        return;
    }
    if (s[35-i]^'1')
        process(s, i+1, cur);
    if (s[35-i]^'0')
        process(s, i+1, cur|(1LL<<i));
}

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
            string x; ll ind=0, val;
            ss >> type >> val;
            for (int i=4; s[i]^']'; ++i)
                ind=ind*10+(s[i]-'0');
            for (int i=0; i<36; ++i) {
                if (ind&(1LL<<i))
                    x.push_back('1');
                else
                    x.push_back('0');
            }
            reverse(x.begin(), x.end());
            for (int i=0; i<36; ++i)
                if (msk[i]^'0')
                    x[i]=msk[i];
            nxt.clear();
            process(x);
            for (ll i:nxt)
                mp[i]=val;
        }
    }
    ll ans=0;
    for (auto p:mp)
        ans+=p.second;
    cout << ans << '\n';
}

