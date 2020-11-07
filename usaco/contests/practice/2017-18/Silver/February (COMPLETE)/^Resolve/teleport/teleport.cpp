//Yay got it second try after a small mistake
//Answer is basically absolute min of sum of f(x)=min(|ai-bi|, |ai|+|x-bi|) for all
//ai, bi from i=0 to n-1, which can be calculated by marking slope changes
#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
using ll=long long;

const int mxN=1e5+1;
int n;
ll ans=LLONG_MAX, cur;
map<ll, ll> mp;

int main() {
    ifstream cin("teleport.in");
    ofstream cout("teleport.out");
    cin >> n;
    for (int i=0; i<n; ++i) {
        ll a, b;
        cin >> a >> b;
        cur+=abs(a-b);
        mp[b]+=2;
        if (a>=0 && b>=0) {
            ll dif=max(0LL, b-2*a);
            --mp[b-dif], --mp[b+dif];
        }
        else if ((a>=0 && b<=0) || (a<=0 && b>=0))
            --mp[0], --mp[2*b];
        else {
            ll dif=min(0LL, b-2*a);
            --mp[b-dif], --mp[b+dif];
        }
    }
    ll dif=0, lst=-1e18;
    for (auto p:mp) {
        cur+=dif*(p.fi-lst);
        ans=min(ans, cur);
        dif+=p.se, lst=p.fi;
    }
    cout << ans << '\n';
}

