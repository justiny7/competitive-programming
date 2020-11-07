#include <bits/stdc++.h>
using namespace std;
using ll=long long;

string s;
ll ans;

ll power(ll x) {
    ll ret=1;
    while (x--)
        ret*=9;
    return ret;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> s;
    ll cur=1, n=s.size();
    for (int i=0; i<n; ++i) {
        ans=max(ans, cur*(s[i]-'0'-1==0?1:(s[i]-'0'-1))*power(n-i-1));
        cur*=s[i]-'0';
    }
    cout << max(cur, ans) << '\n';
}

