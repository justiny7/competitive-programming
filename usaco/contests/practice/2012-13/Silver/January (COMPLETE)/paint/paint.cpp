//Yay worked first try
#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
using ll=long long;

ifstream fin("paint.in");
ofstream fout("paint.out");

ll n, k, ans;
map<ll, ll> mp;

int main() {
    fin >> n >> k;
    int cpos=0;
    while (n--) {
        ll a; char c;
        fin >> a >> c;
        if (c=='R')
            ++mp[cpos], cpos+=a, --mp[cpos];
        else
            --mp[cpos], cpos-=a, ++mp[cpos];
    }
    ll cur=0, last=INT_MAX;
    for (auto& p:mp) {
        cur+=p.se;
        if (cur>=k && last==INT_MAX)
            last=p.fi;
        else if (cur<k && last!=INT_MAX)
            ans+=p.fi-last, last=INT_MAX;
    }
    fout << ans << '\n';
}

