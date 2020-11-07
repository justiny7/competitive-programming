#include <bits/stdc++.h>
using namespace std;
using ll=long long;

const int mxN=2e5+1;
ll n, k, a, b, ans=LLONG_MAX, ans2;

ll gcd(ll a, ll b) {
    return (b?gcd(b, a%b):a);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> k >> a >> b;
    ll p=n*k;
    for (int i=0; i<=n; ++i) {
        ll c=i*k-a+b, c2=(i+1)*k-a-b;
        if (c>0)
            ans=min(ans, p/gcd(p, c)),
            ans2=max(ans2, p/gcd(p, c));
        if (c2>0)
            ans=min(ans, p/gcd(p, c2)),
            ans2=max(ans2, p/gcd(p, c2));
    }
    cout << ans << " " << ans2 << '\n';
}

